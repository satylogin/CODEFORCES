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

int arr[1000000], val[1000000], mark[1000000];
int freq[1000000];

void sieve() {
	int i, j;
	for (i = 2; i*i <= 500000; ++i) {
		if (arr[i] == 0) {
			for (j = i+i; j <= 500000; j += i) {
				if (!arr[j]) arr[j] = i;
			}
		}
	}
	for (i = 2; i <= 500000; ++i) {
		if (!arr[i]) arr[i] = i;
	}
}

int main()
{
	sieve();
	int tmp, n, q, i, j, k, a, b, c, x, y, z, lim, tot;
	ll ans;

	sci(n); sci(q);
	for (i = 1; i <= n; ++i) {
		sci(val[i]);
	}

	ans = 0ll;
	tot = 0;
	int c1 = 0;
	while (q--) {
		sci(x);
		a = val[x];

		vector <int> v;

		while (a != 1) {
			k = arr[a];
			v.pb(k);
			while (a%k == 0) a /= k;
		}

		lim = (1<<v.size());
		tmp = 0;	
		for (i = 1; i < lim; ++i) {
			if (__builtin_popcount(i)&1) {
				a = 1;
			} else {
				a = -1;
			}
			y = 1;
			for (j = 0; j < v.size(); ++j) {
				if (i&(1<<j)) y *= v[j];
			}
			tmp += (a*freq[y]);
		}

		if (mark[x] == 0) {
			mark[x] = 1;
			ans += (tot-tmp);
			tot++;
			for (i = 1; i < lim; ++i) {
				y = 1;
				for (j = 0; j < v.size(); ++j) {
					if (i&(1<<j)) {
						y *= v[j];
					}
				}
				freq[y]++;
			}
		} else {
			mark[x] = 0;
			if (val[x] == 1) ans -= (tot-1);
			else ans -= (tot-tmp);
			tot--;
			for (i = 1; i < lim; ++i) {
				y = 1;
				for (j = 0; j < v.size(); ++j) {
					if (i&(1<<j)) {
						y *= v[j];
					}
				}
				freq[y]--;
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
