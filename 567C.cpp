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

ll dp[200001][4], arr[200001];
map <ll, ll> mp;
set <ll> se;

int main()
{
	ll n, k, i, j, a, b, c, x, y, z;

	cin >> n >> k;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	for (i = n-1; i >= 0; --i) {
		a = arr[i];
		b = arr[i] * k;
		if (mp.find(b) != mp.end()) {
			dp[i][3] = dp[mp[b]][2];
			dp[i][2] = dp[mp[b]][1];
		}
		dp[i][1] = 1;
		if (mp.find(a) != mp.end()) {
			dp[i][3] += dp[mp[a]][3];
			dp[i][2] += dp[mp[a]][2];
			dp[i][1] += dp[mp[a]][1];
		}
		mp[a] = i;
	}

	ll ans = 0;
	for (i = 0; i < n; ++i) {
		if (se.find(arr[i]) == se.end()) {
			se.insert(arr[i]);
			ans += dp[i][3];
		}
	}

	cout << ans << endl;

	return 0;
}
