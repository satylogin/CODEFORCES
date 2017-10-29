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
#define deb 0

#define N 100000
#define LG 20

vector<int> V[LG+5][N+5], S[N+5], v[N+5];
int P[LG+5][N+5], n, L[N+5];

vector<int> merge(vector<int> &a, vector<int> &b)
{
	vector<int> c;
	int i = 0, j = 0;
	while (i < a.size() && j < b.size() && c.size() < 12) {
		if (a[i] <= b[j]) c.pb(a[i++]);
		else c.pb(b[j++]);
	}
	while (i < a.size() && c.size() < 12) {
		c.pb(a[i++]);
	}
	while (j < b.size() && c.size() < 12) {
		c.pb(b[j++]);
	}

	return c;
}

void dfs(int x, int p, int l)
{
	P[0][x] = p;
	V[0][x] = merge(V[0][x], S[x]);
	L[x] = l;
	for (int y: v[x]) {
		if (y == p) continue;
		dfs(y, x, l+1);
	}
}

void make()
{
	for (int i = 1; i <= LG; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (P[i-1][j] == 0) continue;
			P[i][j] = P[i-1][P[i-1][j]];
			V[i][j] = merge(V[i-1][P[i-1][j]], V[i-1][j]);
		}
	}
}

void print(vector<int> v)
{
	for (auto it: v) cout << it << " "; cout << endl;
}

vector<int> query(int x, int y)
{
	if (L[x] < L[y]) swap(x, y);
	int i, j, k;
	k = L[x] - L[y];
	vector<int> ans;

	for (i = LG; i >= 0; --i) {
		if (k&(1<<i)) {
			ans = merge(ans, V[i][x]);
			x = P[i][x];
		}
	}
	if (x == y) {
		ans = merge(ans, S[x]);
		return ans;
	}

	for (i = LG; i >= 0; --i) {
		if (P[i][x] != P[i][y]) {
			ans = merge(ans, V[i][x]);
			ans = merge(ans, V[i][y]);

			x = P[i][x];
			y = P[i][y];
		}
	}
	ans = merge(ans, V[0][x]);
	ans = merge(ans, V[0][y]);
	x = P[0][x];
	ans = merge(ans, S[x]);

	return ans;
}

set<int> se[N+5];

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int m, q, i, j, k, x, y, z, a, b, c;
	cin >> n >> m >> q;
	for (i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}
	for (i = 1; i <= m; ++i) {
		cin >> x;
		se[x].insert(i);
	}
	for (i = 1; i <= n; ++i) {
		while (S[i].size() < 12 && !se[i].empty()) {
			S[i].pb(*se[i].begin());
			se[i].erase(se[i].begin());
		}
	}
	dfs(1, 0, 1);
	make();
	while (q--) {
		cin >> x >> y >> a;
		vector<int> ans = query(x, y);
		if (ans.size() < a) cout << ans.size() << " ";
		else cout << a << " ";
		for (i = 0; i < ans.size() && i < a; ++i) cout << ans[i] << " "; cout << endl;
	}

	return 0;
}
