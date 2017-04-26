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

ll arr[100001];
ll val[100001];
ll a[100001], b[100001], mx[100001], mn[100001];

int main()
{
	ll n, i, j, k, c, x, y, z;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (i = 1; i < n; ++i) {
		arr[i] = abs(arr[i]-arr[i+1]);
	}

	for (i = 1; i < n; ++i) {
		if (i&1) {
			a[i] = arr[i] + a[i-1];
			b[i] = b[i-1];
		} else {
			b[i] = arr[i] + b[i-1];
			a[i] = a[i-1];
		}
		val[i] = a[i]-b[i];
	}
	mx[n-1] = mn[n-1] = val[n-1];
	for (i = n-2; i > 0; --i) {
		mx[i] = max(mx[i+1], val[i]);
		mn[i] = min(mn[i+1], val[i]);
	}

	ll ans = 0;
	for (i = 1; i <= n; ++i) {
		if (i&1) {
			ans = max(mx[i] - val[i-1], ans);
		} else {
			ans = max(-(mn[i] - val[i-1]), ans);
		}
	}
	cout << ans << endl;

	return 0;
}
