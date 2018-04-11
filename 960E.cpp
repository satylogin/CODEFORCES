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

#define N 200000

ll ans = 0, n;
ll V[N+5], E[N+5], O[N+5], SZ[N+5];
vector<ll> v[N+5];

void dfs(ll x, ll p) {
	E[x] = 1;
	SZ[x] = 1;
	for (ll y: v[x]) {
		if (y == p) continue;
		dfs(y, x);
		SZ[x] += SZ[y];
		E[x] += O[y];
		O[x] += E[y];
	}
}

void calc(ll x, ll p, ll e, ll o) {
	ll _e = e - 1;
	ll _o = o;
	for (int y: v[x]) {
		if (y == p) continue;
		calc(y, x, o, e);
		ll prod1 = (((n - SZ[y]) * O[y]) % MOD * V[x]) % MOD;
		ll prod2 = (((n - SZ[y]) * E[y]) % MOD * V[x]) % MOD;
		ans = (ans + prod1 - prod2 + MOD + MOD + MOD) % MOD;
		_e -= O[y];
		_o -= E[y];
	}
	ll prod1 = ((SZ[x] * _e) % MOD * V[x]) % MOD;
	ll prod2 = ((SZ[x] * _o) % MOD * V[x]) % MOD;
	ans = (ans + prod1 - prod2 + MOD + MOD + MOD) % MOD;
	ans = (ans + n * V[x]) % MOD;
	if (ans < 0) ans += MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	ll i, j, k, x, y, z, a, b, c;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> V[i];
	for (i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1, 0);
	calc(1, 0, E[1], O[1]);
	cout << ans << endl;

	return 0;
}
