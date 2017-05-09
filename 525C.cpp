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

ll arr[1000001];

int main()
{
	ll n, i, j, k, a, b, c, x, y, z;

	scl(n);
	for (i = 0; i < n; ++i) {
		scl(arr[i]);	
	}
	sort(arr, arr+n);
	
	a = b = -1;
	ll ans = 0;
	i = n-1;
	while (i > 0) {
		if (arr[i] - arr[i-1] <= 1) {
			if (a == -1) a = arr[i-1];
			else ans += (a*arr[i-1]), a = -1;
			i -= 2;
		} else --i;
	}
	printf("%lld\n", ans);

	return 0;
}
