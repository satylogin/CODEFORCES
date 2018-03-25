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

vector<int> vv[100001], g[100001];
int n, low[100001], disc[100001], vis[100001], timer;
int gl[100001], outdeg[100001], ans[100001], u[100001];
stack<int> st;
set<int> v[100001], r[100001];

void scc(int x) {
	low[x] = disc[x] = vis[x] = ++timer;
	st.push(x);
	for (int y: vv[x]) {
		if (!disc[y]) scc(y);
		if (vis[y]) low[x] = min(low[x], low[y]);
	}
	if (disc[x] == low[x]) {
		while (true) {
			int y = st.top();
			st.pop();
			vis[y] = 0;
			g[x].pb(y);
			gl[y] = x;
			if (y == x) break;
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		for (int y: vv[i]) {
			if (gl[i] != gl[y]) {
				v[gl[i]].insert(gl[y]);
				r[gl[y]].insert(gl[i]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) outdeg[gl[i]] = v[gl[i]].size();
	queue<int> q;
	for (int i = 1; i <= n; ++i) ans[i] = g[i].size();
	for (int i = 1; i <= n; ++i) {
		if (outdeg[i] == 0 && gl[i] == i) {
			q.push(i);
		}
	}
	int val = MOD;
	int x;
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		if (ans[y] < val) {
			val = ans[y];
			x = y;
		}
	}
	q.push(x);
	vector<int> ele;
	memset(vis, 0, sizeof(vis));
	vis[x] = 1;
	while (!q.empty()) {
		x = q.front();
		q.pop();
		for (int y: g[x]) ele.pb(y);
		for (int y: v[x]) {
			if (!vis[y]) {
				vis[y] = 1;
				q.push(y);
			}
		}
	}
	cout << ele.size() << endl;
	for (int x: ele) cout << x << " "; cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int m, h, i, j, k, x, y, z;
	cin >> n >> m >> h;
	for (i = 1; i <= n; ++i) cin >> u[i];
	while (m--) {
		cin >> x >> y;
		if ((u[x] + 1) % h == u[y]) vv[x].pb(y);
		if ((u[y] + 1) % h == u[x]) vv[y].pb(x);
	}
	for (i = 1; i <= n; ++i) {
		if (!disc[i]) scc(i);
	}
	solve();

	return 0;
}
