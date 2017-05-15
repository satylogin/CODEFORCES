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

int mark[1000001];

ll get(ll h, ll a, ll x, ll y, ll m, int f)
{
	ll ans = 0;
	memset(mark, 0, sizeof(mark));
	while (h != a || f == 0) {
		++ans;
		if (mark[h]) {
			return -1;
		}
		if (f) mark[h] = 1;
		f = 1;
		h = (x * h + y) % m;
	}
	return ans;
}

int main()
{
	ll m, i, j, k, h1, a1, x1, y1, h2, a2, x2, y2, t1, td1, t2, td2;
	ll x, y, z, a, b, c, d;

	cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
	t1 = get(h1, a1, x1, y1, m, 1);
	td1 = get(a1, a1, x1, y1, m, 0);
	t2 = get(h2, a2, x2, y2, m, 1);
	td2 = get(a2, a2, x2, y2, m, 0);

	//cout << t1 << " " << td1 << " " << t2 << " " << td2 << endl;

	if (t1 != -1 && t2 != -1) {
		if (t1 == t2) {
			cout << t1 << endl;
			return 0;
		} else if (td1 == -1 && td2 != -1) {
			x = (t1-t2) % td2;
			y = (t1-t2) / td1;
			if (x!=0 || (y<0)) {
				cout << -1 << endl;
			} else {
				cout << t1 << endl;
			}
			return 0;
		} else if (td1 != -1 && td2 == -1) {
			x = (t2-t1) % td1;
			y = (t2-t1) / td1;
			if (x != 0 || y < 0) {
				cout << -1 << endl;
			} else {
				cout << t2 << endl;
			}
			return 0;
		}
	}

	if (t1 == -1 || t2 == -1 || td1 == -1 || td2 == -1) {
		cout << -1 << endl;
		return 0;
	}

	ll inf = MOD;
	inf *= MOD;
	ll ans = inf;

	a = t2 - t1;
	for (i = 0; i < 10000000; ++i) {
		x = (a + i*td2) % td1;
		y = (a + i*td2) / td1;
		if (x != 0) continue;
		ans = min(ans, t1 + y * td1);
	}
	if (ans == inf) ans = -1;
	cout << ans << endl;

	return 0;
}
