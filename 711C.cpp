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

ll dp[101][101][101];
ll col[101], cost[101][101];
ll n, m, K, inf;

ll get(ll idx, ll last, ll c)
{
	if (idx == n+1) {
		if (c == K) return 0;
		else return inf;
	}
	if (c > K) return inf;

	if (dp[idx][last][c] != -1) return dp[idx][last][c];

	if (col[idx] == 0) {
		dp[idx][last][c] = inf;
		ll x = 0;
		for (ll i = 1; i <= m; ++i) {
			x = (i != last);
			dp[idx][last][c] = min(dp[idx][last][c], cost[idx][i] + get(idx+1, i, c+x));
		}
		return dp[idx][last][c];
	} else {
		if (col[idx] == last) {
			return dp[idx][last][c] = get(idx+1, col[idx], c);
		} else {
			return dp[idx][last][c] = get(idx+1, col[idx], c+1);
		}
	}
}

int main()
{
	ll k, i, j, a, b, c;
	inf = MOD;
	inf *= MOD;
	memset(dp, -1, sizeof(dp));

	cin >> n >> m >> K;
	for (i = 1; i <= n; ++i) {
		cin >> col[i];	
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			cin >> cost[i][j];
		}
	}

	a = get(1, 0, 0);
	if (a == inf) a = -1;
	cout << a << endl;

	return 0;
}
