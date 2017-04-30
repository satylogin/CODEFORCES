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

pii arr[1000];

int main()
{
	int n, i, j, k, x, y, a, b, c, l, r, u, d;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> arr[i].fi >> arr[i].sc;

	c = 0;
	for (i = 0; i < n; ++i) {
		l = r = u = d = 0;
		for (j = 0; j < n; ++j) {
			if (arr[i].fi == arr[j].fi) {
				u |= (arr[j].sc > arr[i].sc);
				d |= (arr[j].sc < arr[i].sc);
			} 
			if (arr[i].sc == arr[j].sc) {
				l |= (arr[j].fi < arr[i].fi);
				r |= (arr[j].fi > arr[i].fi);
			}
		}
		c += (l&r&u&d);
	}
	cout << c << endl;

	return 0;
}
