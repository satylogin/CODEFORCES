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

int main()
{
	ll n, i, j, k, a, b, c, x, y, z;
	ll ans = 0;
	cin >> n;

	x = 0;
	y = 9;
	j = 1;
	while (1) {
		if (y < n)  {
			ans += j * (y-x);
		} else {
			ans += j * (n-x);
			break;
		}
		j++;
		x = y;
		y = y * 10 + 9;
	}
	cout << ans << endl;

	return 0;
}
