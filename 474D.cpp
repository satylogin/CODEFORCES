#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll ans[100001];

int main()
{
	ll i, n, k, a, b;
	cin >> n >> k;
	ans[0] = 1ll;
	for (i = 1; i <= 100000; ++i) {
		ans[i] = ans[i-1];
		if (i >= k) ans[i] += ans[i-k];
		//if (i <= 4) cout << i << " " << ans[i] << endl;
		if (ans[i] >= MOD) ans[i] -= MOD;
	}
	for (i = 1; i <= 100000; ++i) {
		ans[i] += ans[i-1];
		if (ans[i] >= MOD) ans[i] -= MOD;
	}
	while (n--) {
		cin >> a >> b;
		cout << (ans[b] - ans[a-1] + MOD) % MOD << endl;
	}

	return 0;
}
