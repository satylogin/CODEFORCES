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

int h[1000000], v[1000000];
int hn[1000000], vn[1000000], lh, lv;
pair <char, int> qry[1000000];
ll ans[1000000];
set <int> sev, seh;

int main()
{
	int n, m, q, i, j, k, a, b, c, x, y, z;
	ll hmax, vmax;
	char ch, st[2];

	sci(n); sci(m); sci(q);
	
	++lv, ++lh;
	for (i = 0; i < q; ++i) {
		scanf("%s %d", st, &x);
		ch = st[0];
		qry[i] = mkp(ch, x);
		if (ch == 'H') {
			v[lv++] = x;
			sev.insert(x);
		} else {
			h[lh++] = x;
			seh.insert(x);
		}
	}
	v[lv++] = m;
	sev.insert(m);
	h[lh++] = n;
	seh.insert(n);

	sort(v, v+lv);
	sort(h, h+lh);
	hmax = vmax = 0;

	x = 0;
	for (i = 1; i < lv; ++i) {
		vn[v[i]] = x;
		vmax = max(vmax, (ll) v[i]-x);
		x = v[i];
	}

	x = 0;
	for (i = 1; i < lh; ++i) {
		hn[h[i]] = x;
		hmax = max(hmax, (ll) h[i]-x);
		x = h[i];
	}

	for (i = q-1; i >= 0; --i) {
		ans[i] = hmax * vmax;
		ch = qry[i].fi;
		x = qry[i].sc;
		if (ch == 'H') {
			y = *sev.upper_bound(x);
			vn[y] = vn[x];
			vmax = max(vmax, (ll) y-vn[y]);
			sev.erase(x);
		} else if (ch == 'V') {
			y = *seh.upper_bound(x);
			hn[y] = hn[x];
			hmax = max(hmax, (ll) y-hn[y]);
			seh.erase(x);
		}
	}

	for (i = 0; i < q; ++i) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}
