#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[1000], n;
int dp[1000][5];

int get(int i, int last)
{
	if (i == n) return 0;
	if (dp[i][last] != -1) return dp[i][last];
	if (last == 0) {
		dp[i][last] = 1 + get(i+1, 0);
		switch (arr[i]) {
			case 1:
				dp[i][last] = min(get(i+1, 1), dp[i][last]); break;
			case 2:
				dp[i][last] = min(get(i+1, 2), dp[i][last]); break;
			case 3:
				dp[i][last] = min(dp[i][last], min(get(i+1, 1), get(i+1, 2))); break;
		}
	} else if (last == 1) {
		dp[i][last] = 1 + get(i+1, 0);
		switch (arr[i]) {
			case 2:
			case 3: 
				dp[i][last] = min(dp[i][last], get(i+1, 2));
		}
	} else if (last == 2) {
		dp[i][last] = 1 + get(i+1, 0);
		switch (arr[i]) {
			case 1:
			case 3: 
				dp[i][last] = min(dp[i][last], get(i+1, 1));
		}
	}
	//cout << "i = " << i << " last = " << last << " dp = " << dp[i][last] << endl;
	return dp[i][last];
}

int main()
{
	int m, i, j, k, a, b, c;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << get(0, 0) << endl;

	return 0;
}
