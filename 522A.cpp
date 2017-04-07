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

string p1[300], p2[300], tmp;
map <string, int> mp;
int dp[1000];

int main()
{
	int n, i, j, k, x;
	sci(n);
	k = 0;
	dp[0] = 1;
	x = 0;
	for (i = 0; i < n; ++i) {
		cin >> p1[i] >> tmp >> p2[i];
		for (j = 0; p1[i][j]; ++j) {
			if (p1[i][j] >= 'A' && p1[i][j] <= 'Z') {
				p1[i][j] = p1[i][j] - 'A' + 'a';
			}
		}
		for (j = 0; p2[i][j]; ++j) {
			if (p2[i][j] >= 'A' && p2[i][j] <= 'Z') {
				p2[i][j] = p2[i][j] - 'A' + 'a';
			}
		}
		if (mp.find(p2[i]) == mp.end()) mp[p2[i]] = k++;	
		if (mp.find(p1[i]) == mp.end()) mp[p1[i]] = k++;
		dp[mp[p1[i]]] = max(dp[mp[p1[i]]], 1 + dp[mp[p2[i]]]);
		x = max(x, dp[mp[p1[i]]]);
	}
	cout << x << endl;

	return 0;
}
