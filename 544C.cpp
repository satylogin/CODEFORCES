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

int n, m, b, mod;
ll arr[1000], dp[2][501][501];

int main()
{
	int i, j, k, it;
	cin >> n >> m >> b >> mod;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	dp[0][0][0] = 1;
	for (it = 1; it <= n; ++it) {
		i = it&1;
		for (j = 0; j <= m; ++j) {
			for (k = 0; k <= b; ++k) {
				dp[i][j][k] = dp[i^1][j][k];
				if (j > 0 && k >= arr[it]) {
					dp[i][j][k] += dp[i][j-1][k-arr[it]];
				}	
				dp[i][j][k] %= mod;
			}
		}
	}
	ll c = 0;
	for (i = 0; i <= b; ++i) {
		c += dp[n&1][m][i];
		if (c >= mod) c -= mod;
	}
	
	cout << c << endl;

	return 0;
}
