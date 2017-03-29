#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll arr[1000001];
vector <ll> v;

int main()
{
	ll n, m, i, j, k, a, b, c;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	if (arr[n]%3 != 0) {
		cout << 0 << endl;
		return 0;
	}
	a = arr[n] / 3;
	b = a + a;
	c = 0;
	for (i = 2; i < n; ++i) {
		if (arr[i] == b) {
			v.pb(i);
		}
	}

	j = 0;
	k = v.size();
	for (i = 1; i < n-1; ++i) {
		if (arr[i] == a) {
			while (j < k && v[j] <= i) j++;
			c += (k-j);
		}
	}
	cout << c << endl;

	return 0;
}
