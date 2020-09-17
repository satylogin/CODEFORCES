#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 998244353
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

long long inv(long long a) {
	a %= MOD;
	long long b = MOD - 2, ans = 1;
	while (b) {
		if (b&1) ans = (ans * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;

	vector<long long> A(n+1, 0), P(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for (int i = 1; i <= n; ++i) {
		P[i] = (P[i-1] + A[i]) % MOD;
	}
	while (m--) {
		cin >> a >> b;
		int idx = lower_bound(A.begin(), A.end(), b) - A.begin() - 1;
		long long big = n - idx;
		if (big < a) cout << 0 << endl;
		else {
			ll x = ((big - a) * (P[n] - P[idx] + MOD) % MOD) * inv(big) % MOD;
			ll y = ((big + 1 - a) * P[idx] % MOD) * inv(big + 1) % MOD;
			cout << (x + y) % MOD << endl;
		}
	}
 
 
	return 0;
}
