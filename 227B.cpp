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

int arr[100001];

int main()
{
	int n, i, j, k, x;
	sci(n);
	for (i = 1; i <= n; ++i) {
		sci(x);
		arr[x] = i;
	}
	sci(k);

	ll a, b;
	a = b = 0;
	while (k--) {
		sci(x);
		a += arr[x];
		b += (n - arr[x] + 1);
	}
	cout << a << " " << b << endl;

	return 0;
}
