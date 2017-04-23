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

int main()
{
	ll a, b, q, m, start, mid, end, l, t, i, j, k, ans;
	cin >> a >> b >> q;

	ll x, y;
	while (q--) {
		cin >> l >> t >> m;
	
		start = l;
		end = 1000000000ll;
		ans = -1;
		while (start <= end) {
			mid = (start + end) >> 1;
			x = a * (mid - l + 1);
			y = b * (mid * (mid - 1) / 2);
			if (l > 1) y -= b * ((l-2) * (l - 1) / 2);
			if (a + (mid - 1) * b <= t && x+y <= m*t) {
				ans = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
