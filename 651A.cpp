#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int dp[1000][1000];

int get(int x, int y)
{
	if (x <= 0 || y <= 0) return 0;
	if (dp[x][y] != -1) return dp[x][y];
	if (x == 1 && y != 1) dp[x][y] = 1 + get(x+1, y-2);
	else if (x != 1 && y == 1) dp[x][y]= 1 + get(x-2, y+1);
	else if (x == 1 && y == 1) return 0;
	else dp[x][y] = 1 + max(get(x+1, y-2), get(x-2, y+1));
	return dp[x][y];
}	

int main()
{
	memset(dp, -1, sizeof(dp));
	int x, y;
	cin >> x >> y;
	cout << get(x, y) << endl;

	return 0;
}
