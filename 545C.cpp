#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int n, xi[100001], hi[100001];
map <pair<int, int>, int> dp;

int get(int i, int last)
{
	if (i == n) return 0;
	if (dp.find(mkp(i, last)) != dp.end()) return dp[mkp(i, last)];
	//if (dp[i][last] != -1) return dp[i][last];
	int a, b, c;
	if (xi[i]-hi[i] > last) a = 1 + get(i+1, xi[i]);
	else a = 0;
	if (xi[i]+hi[i] < xi[i+1]) b = 1 + get(i+1, xi[i]+hi[i]);
	else b = 0;
	c = 0 + get(i+1, xi[i]);
	return dp[mkp(i, last)] = max(a, max(b, c));
}

int main()
{
	int m, i, j, k, a, b, c;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> xi[i] >> hi[i];
	}
	xi[n] = MOD + MOD;

	//memset(dp, -1, sizeof(dp));
	cout << get(0, -MOD) << endl;

	return 0;
}
