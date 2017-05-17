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

ll mark[1000000], match[1000000];
ll arr[1000000], fw[1000000], bw[1000000];
ll n, m;
set <ll> mis;

void fill(ll &d, ll &tmp, ll &x)
{
	ll i, j, k, a, b, c;
	for (i = 0; i < m; ++i) {
		if (x == n && d == 0) d = 1;
		if (x == 1 && d == 1) d = 0;
		mark[x]++;
		if (d == 0) x++, tmp += fw[x];
		else x--, tmp += bw[x];
	}
	if (d == 0) tmp -= fw[x], x--;
	else tmp -= bw[x], x++;
}

void check(ll &x, ll &y, ll &ans, ll tmp, ll &d)
{
	while (x <= n) {
		if (mis.empty()) {
			if (ans == -1) {
				ans = tmp;
			} else {
				if (ans != tmp) {
					cout << -1 << endl;
					exit(0);
				}
			}
		}
		if (y == n && d == 0) d = 1;
		if (y == 1 && d == 1) d = 0;
		mark[x]--;
		if (mark[x] != match[x]) mis.insert(x);
		if (mark[x] == match[x]) mis.erase(mis.find(x));

		x++;
		tmp -= fw[x];
		if (d == 0) y++, tmp += fw[y], mark[y]++;
		else y--, tmp += bw[y], mark[y]++;

		if (mark[y] != match[y]) mis.insert(y);
		if (mark[y] == match[y]) mis.erase(mis.find(y));
	}
}

void check1(ll &x, ll &y, ll &ans, ll tmp, ll &d)
{
	while (x > 0) {
		if (mis.empty()) {
			if (ans == -1) {
				ans = tmp;
			} else {
				if (ans != tmp) {
					cout << -1 << endl;
					exit(0);
				}
			}
		}
		if (y == n && d == 0) d = 1;
		if (y == 1 && d == 1) d = 0;
		mark[x]--;
		if (mark[x] != match[x]) mis.insert(x);
		if (mark[x] == match[x]) mis.erase(mis.find(x));

		x--;
		tmp -= bw[x];
		if (d == 0) y++, tmp += fw[y], mark[y]++;
		else y--, tmp += bw[y], mark[y]++;

		if (mark[y] != match[y]) mis.insert(y);
		if (mark[y] == match[y]) mis.erase(mis.find(y));
	}
}

int main()
{
	ll i, j, k, d, a, b, c, x, y, z;
	scl(n); for (i = 1; i <= n; ++i) { scl(arr[i]); fw[i] = bw[i-1] = arr[i] - arr[i-1]; }		
	scl(m); for (i = 0; i < m; ++i) { scl(x); match[x]++; }
	ll tmp, ans = -1;
/*
	if (m == 1) {
		cout << 0 << endl;
		return 0;
	}
*/
	x = 1; tmp = 0; d = 0;
	memset(mark, 0, sizeof(mark));
	fill(d, tmp, x);

	mis.clear();
	for (i = 1; i <= n; ++i) {
		if (match[i] != mark[i]) mis.insert(i);
	}

	//for (i = 1; i <= n; ++i) cout << match[i] << " "; cout << endl;
	//for (i = 1; i <= n; ++i) cout << mark[i] << " "; cout << endl;

	y = x; x = 1;

	//cout << x << " " << y << " " << tmp << " " << d <<endl;
	check(x, y, ans, tmp, d);
	//cout << ans << endl;

	x = n; tmp = 0; d = 1;
	memset(mark, 0, sizeof(mark));
	fill(d, tmp, x);

	mis.clear();
	for (i = 1; i <= n; ++i) {
		if (match[i] != mark[i]) mis.insert(i);
	}

	y = x; x = n;
	check1(x, y, ans, tmp, d);

	cout << ans << endl;

	return 0;
}
