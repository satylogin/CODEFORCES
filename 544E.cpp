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

int d[1<<20], sv[30][30], a[30][30], c[30][30];
char str[30][30];

int main()
{
	int n, m, i, j, k, x, y, lim, mask;
	cin >> n >> m;
	for (i = 0; i < n; ++i) cin >> str[i];
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) 
			cin >> a[i][j];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			x = 0;
			for (k = 0; k < n; ++k) {
				if (str[i][j] == str[k][j]) {
					sv[i][j] |= (1<<k);
					c[i][j] += a[k][j];
					x = max(x, a[k][j]);
				}
			}
			c[i][j] -= x;
		}
	}

	lim = (1<<n)-1;
	for (i = 0; i <= lim; ++i) d[i] = MOD;
	d[0] = 0;
	for (mask = 1; mask <= lim; ++mask) {
		x = 0;
		for (i = 0; i < n; ++i) {
			if (mask&(1<<i)) {
				x = i;
				break;
			}
		}
		for (i = 0; i < m; ++i) {
			d[mask] = min(d[mask], d[mask & (mask ^ sv[x][i])] + c[x][i]);
			d[mask] = min(d[mask], d[mask ^ (1<<x)] + a[x][i]);
		}
	}

	cout << d[lim] << endl;

	return 0;
}
