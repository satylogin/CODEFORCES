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

vector <pii> v, arr, p;

int main()
{
	ll n, i, j, k, a, b, c, x, y, z;
	cin >> n;

	for (i = 0; i < n; ++i) {
		cin >> x >> y;
		arr.pb(mkp(x, y));
	}

	ll ans = 0;
	for (i = 0; i < n; ++i) {
		v.clear();
		for (j = i+1; j < n; ++j) {
			x = arr[j].fi - arr[i].fi;
			y = arr[j].sc - arr[i].sc;
			z = __gcd(abs(x), abs(y));
			x /= z;
			y /= z;
			if (x<0) {
				x *= -1;
				y *= -1;
			}
			if (x == 0) {
				v.pb(mkp(MOD, MOD));
			} else if (y == 0) {
				v.pb(mkp(0, 0));
			} else {
				v.pb(mkp(x, y));
			}
		}
		sort(v.begin(), v.end());
		x = 1;
		for (j = 1; j < v.size(); ++j) {
			if (v[j] == v[j-1]) x++;
			else {
				ans += x*(v.size()-j);
				x = 1;
			}
		}
	}	
	cout << ans << endl;

	return 0;
}
