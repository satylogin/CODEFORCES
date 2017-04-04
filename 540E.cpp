#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

set <int> se, se2;
set <int> :: iterator it;
map <int, int> mp, freq, idx;
int q1[100001], q2[100001];
int BIT[1000001], arr[1000001];

void insert(int x, int val)
{
	for (; x <= 1000000; x += (x&-x))
		BIT[x] += val;
}

int query(int x)
{
	int sum = 0;
	for (; x > 0; x -= (x&-x))
		sum += BIT[x];
	return sum;		
}

int main()
{
	int n, i, j, k, a, b, c, x, y, z;
	sci(n);
	ll ans = 0;
	for (i = 0; i < n; ++i) {
		sci(q1[i]); sci(q2[i]);
		se.insert(q1[i]);
		se.insert(q2[i]);
	}

	int prev = 0;
	for (it = se.begin(); it != se.end(); ++it) {
		x = *it;
		if (x != prev+1) {
			freq[x-1] = x-1-prev;
			se2.insert(x-1);
		}
		freq[x] = 1;
		se2.insert(x);
		prev = x;
	}

	i = 1;
	for (it = se2.begin(); it != se2.end(); ++it) {
		mp[*it] = i;
		idx[i] = i;
		freq[i] = freq[*it];
		i++;
	}
	c = i-1;

	for (i = 0; i < n; ++i) {
		a = mp[q1[i]]; b = mp[q2[i]];
		x = idx[a];
		idx[a] = idx[b];
		idx[b] = x;
	}

	for (i = 1; i <= c; ++i) {
		arr[idx[i]] = i;
	}
/*
	for (i = 1; i <= c; ++i) {
		cout << arr[i] << " " << freq[arr[i]] << endl;
	}
*/
	for (i = c; i > 0; --i) {
		ans += (query(arr[i]-1) * ((ll)freq[arr[i]]));
		insert(arr[i], freq[arr[i]]);
	}

	cout << ans << endl;

	return 0;
}
