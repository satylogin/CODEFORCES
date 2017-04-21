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

char str[1000001];
vector <int> v;

int main()
{
	int t, i, j, k, len = 0;
	ll x, y;
	ll ans = 0;
	cin >> k;
	scanf("%s", str);
	if (k == 0) {
		ans = 0;
		x = 0;
		for (i = 0; str[i]; ++i) {
			if (str[i] == '0') x++;
			else {
				ans += x * (x + 1) / 2;
				x = 0;
			}
		}
		if (x) ans += x * (x + 1) / 2;
		cout << ans << endl;
		return 0;
	}	
	for (i = 0; str[i]; ++i) {
		len++;
		if (str[i] == '1') v.pb(i);
	}

	for (i = 0; str[i]; ++i) {
		x = lower_bound(v.begin(), v.end(), i) - v.begin();
		if (x+k-1 < v.size()) {
			if (x+k < v.size()) {
				ans += v[x+k] - v[x+k-1];
			} else {
				ans += (len - v[x+k-1]);
			}
		}
		
	}
	cout << ans << endl;

	return 0;
}
