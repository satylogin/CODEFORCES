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

ll fact[21];
ll arr1[40], arr2[40];
vector <ll> v1[40], v2[40];

int main()
{
	ll m, s, i, j, k, a, b, c, x, y, z, n;
	fact[0] = 1ll;
	for (i = 1; i <= 18; ++i) {
		fact[i] = i * fact[i-1];
	}

	cin >> n >> m >> s;

	ll ans, n1, n2, lim1, lim2, inf;
	n2 = n / 2;
	n1 = n - n2;
	
	for (i = 0; i < n1; ++i) cin >> arr1[i];
	for (i = 0; i < n2; ++i) cin >> arr2[i];

	lim1 = 1<<n1;
	lim2 = 1<<n2;

	inf = MOD;
	inf *= MOD;

	for (i = 0; i < lim1; ++i) {
		for (j = 0; j < lim1; ++j) {
			if ((j&i) != j) continue;
			ans = 0;
			for (k = 0; k < n1; ++k) {
				if (j&(1<<k)) {
					x = arr1[k];
					if (x > 18 || ans > s - fact[x]) {
						ans = inf;
						break;
					} else {
						ans += fact[x];
					}
				} else if (i&(1<<k)) {
					x = arr1[k];
					if (ans > s - x) {
						ans = inf;
						break;
					} else {
						ans += x;
					}
				}
			}
			if (ans < inf) {
				v1[__builtin_popcount(j)].pb(ans);
			}		
		}
	}

	for (i = 0; i < lim2; ++i) {
		for (j = 0; j < lim2; ++j) {
			if ((j&i) != j) continue;
			ans = 0;
			for (k = 0; k < n2; ++k) {
				if (j&(1<<k)) {
					x = arr2[k];
					if (x > 18 || ans > s - fact[x]) {
						ans = inf;
						break;
					} else {
						ans += fact[x];
					}
				} else if (i&(1<<k)) {
					x = arr2[k];
					if (ans > s - x) {
						ans = inf;
						break;
					} else {
						ans += x;
					}
				}
			}
			if (ans < inf) {
				v2[__builtin_popcount(j)].pb(ans);
			}		
		}
	}

	for (i = 0; i <= 25; ++i) sort(v1[i].begin(), v1[i].end()), sort(v2[i].begin(), v2[i].end());

	ans = 0;
	for (i = 0; i <= 25; ++i) {
		for (j = 0; j+i <= m; ++j) {
			for (x = 0; x < v1[i].size(); ++x) {
				if (v1[i][x] > s) break;
				ans += (upper_bound(v2[j].begin(), v2[j].end(), s-v1[i][x]) - 
						lower_bound(v2[j].begin(), v2[j].end(), s-v1[i][x]));
			}
		}
	}

	cout << ans << endl;

	return 0;
}
