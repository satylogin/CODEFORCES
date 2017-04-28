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
#define fi first
#define sc second

int arr[1000001];
set <int> se[2];
set <int> :: iterator it;

int main()
{
	int n, m, i, x, y, a;
	sci(n); sci(m);
	for (i = 0; i < n; ++i) sci(arr[i]), arr[i] %= m;
	for (i = 0; i < n; ++i) {
		x = i&1;
		y = x^1;
		se[x].insert(arr[i]);
		for (it = se[y].begin(); it != se[y].end(); ++it) {
			a = arr[i] + *it;
			if (a >= m) a -= m;
			se[x].insert(a);
		}
		for (it = se[y].begin(); it != se[y].end(); ++it) {
			se[x].insert(*it);
		}
		if (se[x].find(0) != se[x].end()) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}
