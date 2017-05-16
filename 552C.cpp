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

vector <ll> v2, v1, v, a1, a2;

int main()
{
	ll n, m, i, j, k, a, b, c, x, y, z;
	cin >> n >> m;
	if (n == 2) {
		cout << "YES" << endl;
		return 0;
	}

	i = 1;
	while (v.size() < 24) {
		v.pb(i);
		i *= n;
	}

	ll len1, len2;
	len1 = v.size() / 2;
	len2 = v.size() - len1;

	for (i = 0; i < len1; ++i) v1.pb(v[i]);
	for (; i < v.size(); ++i) v2.pb(v[i]);

	ll lim1, lim2;
	lim1 = (1<<len1);
	lim2 = (1<<len2);

	for (i = 0; i < lim1; ++i) {
		for (j = 0; j < lim1; ++j) {
			if ((i&j) != j) continue;
			x = 0;
			for (k = 0; k < len1; ++k) {
				if (j&(1<<k)) {
					x -= v1[k];
				} else if (i&(1<<k)) {
					x += v1[k];
				}
			}
			a1.pb(x);
		}
	}

	for (i = 0; i < lim2; ++i) {
		for (j = 0; j < lim2; ++j) {
			if ((i&j) != j) continue;
			x = 0;
			for (k = 0; k < len2; ++k) {
				if (j&(1<<k)) {
					x -= v2[k];
				} else if (i&(1<<k)) {
					x += v2[k];
				}
			}
			a2.pb(x);
		}
	}

	sort(a2.begin(), a2.end());

	for (i = 0; i < a1.size(); ++i) {
		if (binary_search(a2.begin(), a2.end(), a1[i]-m)) {
			cout << "YES" << endl;
			return 0;
		}
	}

	cout << "NO" << endl;

	return 0;
}
