#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ll a00, a01, a02, a03, a10, a11, a12, a13;

int main()
{
	ll n, i;
	cin >> n;
	a03 = 1;
	for (i = 1; i <= n; ++i) {
		a10 = (a01 + a02 + a03) % MOD;
		a11 = (a00 + a02 + a03) % MOD;
		a12 = (a01 + a00 + a03) % MOD;
		a13 = (a01 + a02 + a00) % MOD;
		a00 = a10;
		a01 = a11;
		a02 = a12;
		a03 = a13;
	}
	cout << a13 << endl;

	return 0;
}
