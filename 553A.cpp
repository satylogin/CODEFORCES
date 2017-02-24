#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll arr[100001], fact[100001];

ll inv(ll a)
{
	ll b = MOD-2, ans = 1;
	while (b) {
		if (b&1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	ll i, j, n, k, a, b, c, ans = 1;

	fact[0] = 1;
	for (i = 1; i <= 100000; ++i) {
		fact[i] = (i * fact[i-1]) % MOD;
	}

	cin >> n;	
	c = 0;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		c += arr[i];
	}

	for (i = n; i > 0; --i) {
		a = arr[i] - 1;
		c--;
		b = (((fact[c] * inv(fact[a])) % MOD) * inv(fact[c-a])) % MOD;
		if(b != 0) ans = (ans * b) % MOD;

		c -= a;
	}

	cout << ans << endl;

	return 0;
}
