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

ll arr[10001], b[10001];
ll dp[5001][5001], inf;
int n, m;

ll get(int i, int k)
{	
	if (i >= n+1) {
		if (k == 0) return 0;
		else return inf;
	}

	if (dp[i][k] != -1) return dp[i][k];

	if (k > 0) dp[i][k] = max(get(i+1, k), b[i] + get(i+m, k-1));
	else dp[i][k] = get(i+1, k);
	return dp[i][k];
}

int main()
{
	int k, i, j;

	sci(n); sci(m); sci(k);
	for (i = 1; i <= n; ++i) {
		scl(arr[i]);
		arr[i] += arr[i-1];
	}
	for (i = m; i <= n; ++i) {
		b[i] = arr[i] - arr[i-m];
	}
	inf = -MOD;
	inf *= MOD;
	memset(dp, -1, sizeof(dp));
	cout << get(m, k) << endl;

	return 0;
}
