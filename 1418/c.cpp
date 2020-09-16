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
#define eps 1e-9

int get_min_coins_spent(int n, vector<int> &A) {
	vector<vector<int>> DP(2, vector<int>(n+1, 0));
	DP[0][0] = DP[1][1] = MOD;
	DP[0][1] = A[1];
	for (int i = 2; i <= n; ++i) {
		DP[0][i] = min(A[i] + DP[1][i-1], A[i] + A[i-1] + DP[1][i-2]);
		DP[1][i] = min(DP[0][i-1], DP[0][i-2]);
	}

	return min(DP[0][n], DP[1][n]);
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> A(n+1);
		for (int i = 1; i <= n; ++i) cin >> A[i];
		cout << get_min_coins_spent(n, A) << endl;
	}

	return 0;
}
