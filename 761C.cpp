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

char str[100][100];
ll dp[100][100][2][2][2];
int n, m;

ll get(int i, int j, int a, int b, int c)
{
	if (i == n+1) {
		if (a == 1 && b == 1 && c == 1) return 0;
		else return MOD;
	}

	if (j == m+1) return MOD;

	if (dp[i][j][a][b][c] != -1) return dp[i][j][a][b][c];

	int x = a, y = b, z = c;
	if (str[i][j] >= 'a' && str[i][j] <= 'z') {
		x = 1;
	} else if (str[i][j] >= '0' && str[i][j] <= '9') {
		y = 1;
	} else {
		z = 1;
	}

	return dp[i][j][a][b][c] = min(min(j-1, m+1-j) + get(i+1, 1, x, y, z), get(i, j+1, a, b, c));
}

int main()
{
	int i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		scanf("%s", &str[i][1]);
	}

	memset(dp, -1, sizeof(dp));

	cout << get(1, 1, 0, 0, 0) << endl;
	return 0;
}
