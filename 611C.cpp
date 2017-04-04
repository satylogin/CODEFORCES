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

char str[1000][1000];
ll rs[1001][1001], cl[1001][1001];

int main()
{
	int n, m, i, j, k, a, b, c, x, y, z;
	int x1, x2, y1, y2;
	sci(n); sci(m);
	for (i = 1; i <= n; ++i) {
		scanf("%s", &str[i][1]);
		str[i][0] = '\0';
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			if (str[i][j] == '.' && str[i][j-1] == '.') {
				rs[i][j] = 1 + rs[i][j-1];
			} else {
				rs[i][j] = rs[i][j-1];
			}
			if (str[i][j] == '.' && str[i-1][j] == '.') {
				cl[i][j] = 1 + cl[i-1][j];
			} else {
				cl[i][j] = cl[i-1][j];
			}
		}
	}

	sci(z);
	ll ans;
	while (z--) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		ans = 0ll;
		//cout << "rows" << endl;
		for (i = x1; i <= x2; ++i) {
			x = rs[i][y2];
			if (str[i][y1] == '.' && str[i][y1-1] == '.') {
				x = x - rs[i][y1-1] - 1;
			} else {
				x -= rs[i][y1-1];
			}
			ans += x;
			//cout << i << " " << x << " " << ans << endl;
		}	
		//cout << "cols" << endl;
		for (i = y1; i <= y2; ++i) {
			x = cl[x2][i];
			if (str[x1][i] == '.' && str[x1-1][i] == '.') {
				x = x - cl[x1-1][i] - 1;
			} else {
				x -= cl[x1-1][i];
			}
			ans += x;
			//cout << i << " " << x << " " << ans << endl;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
