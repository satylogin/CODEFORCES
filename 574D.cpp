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

int a[100005], mark[100005], dp[100005];
queue <int> q;
vector <int> v[100005];

int main()
{
	int n, i, j, k, x, y, z, p;
	sci(n);

	for (i = 1; i <= n; ++i) {
		sci(a[i]);
		dp[i] = min(a[i], min(i, n-i+1));
		if (dp[i] == 1) q.push(i), mark[i] = 1;
		v[dp[i]].pb(i);
	}

	int ans = 0;
	while (!q.empty()) {
		z = q.size();
		//for (i = 1; i <= n; ++i) cout << dp[i] << " "; cout << endl;
		while (z--) {
			x = q.front();
			ans = max(ans, dp[x]);
			q.pop();
			if (a[x-1] == 0) mark[x-1] = 1;
			if (a[x+1] == 0) mark[x+1] = 1;

			if (!mark[x-1]) {
				dp[x-1] = min(dp[x] + 1, dp[x-1]);
				mark[x-1] = 1;
				q.push(x-1);
			}
			if (!mark[x+1]) {
				dp[x+1] = min(dp[x] + 1, dp[x+1]);
				mark[x+1] = 1;
				q.push(x+1);
			}
		}
		for (i = 0; i < v[dp[x]+1].size(); ++i) {
			if (!mark[v[dp[x]+1][i]]) {
				mark[v[dp[x]+1][i]] = 1;
				q.push(v[dp[x]+1][i]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}
