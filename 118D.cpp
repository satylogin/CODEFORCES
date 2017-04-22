#include <bits/stdc++.h>

using namespace std;

#define MOD 100000000
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)

int N1, N2, K1, K2;
int dp[101][101][11][11];

int get(int n1, int n2, int k1, int k2)
{
	if (n1 > N1 || n2 > N2 || k1 > K1 || k2 > K2) return 0;
	if (n1 == N1 && n2 == N2 && k1 <= K1 && k2 <= K2) return 1;
	if (dp[n1][n2][k1][k2] != -1) return dp[n1][n2][k1][k2];
	int x = 0;
	x += get(n1+1, n2, k1+1, 0);
	if (x >= MOD) x -= MOD;
	x += get(n1, n2+1, 0, k2+1);
	if (x >= MOD) x -= MOD;
	return dp[n1][n2][k1][k2] = x;
}

int main()
{
	cin >> N1 >> N2 >> K1 >> K2;
	memset(dp, -1, sizeof(dp));
	cout << get(0, 0, 0, 0) << endl;

	return 0;
}
