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
#define eps 1e-9
#define PI 3.14159265

const int N = 500005;
vector<vector<pair<int, int>>> G(N);
vector<vector<pair<int, int>>> R(N);
vector<bool> visited(N, false); 
vector<int> color(N, -1);
vector<int> terminal(N, 0);
vector<int> dist(N, 0);

bool is_no_path_possible(int n) {
	queue<int> q;
	q.push(n);
	color[n] = 1;
	visited[n] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		terminal[x] = 1;
		for (auto p: R[x]) {
			int y = p.fi;
			int c = p.sc;
			if (color[y] == -1) {
				color[y] = c ^ 1;
			} else if (color[y] == c) {
				if (!visited[y]) {
					q.push(y);
					visited[y] = 1;
				}
			}
		}
	}

	return !terminal[1];
}

int dij(int x, int n) {
	multiset<pair<int, int>> se;
	se.insert(mkp(0, 1));
	fill(visited.begin(), visited.end(), 0);
	while (!se.empty()) {
		pair<int, int> it = *se.begin();
		se.erase(se.begin());
		x = it.sc;
		if (visited[x]) continue;
		visited[x] = 1;
		dist[x] = it.fi;
		for (auto it: G[x]) {
			int y = it.fi;
			int c = it.sc;
			if (color[x] == c && !visited[y]) {
				se.insert(mkp(dist[x] + 1, y));
			}	
		}
	}

	return dist[n];
}

int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n, m;
	cin >> n >> m;
	int x, y, c;
	while (m--) {
		cin >> x >> y >> c;
		if (x == y) continue;
		G[x].pb(mkp(y, c));
		R[y].pb(mkp(x, c));
	}
	if (is_no_path_possible(n)) {
		cout << -1 << endl;
	} else {
		cout << dij(1, n) << endl;
	}
	for (int i = 1; i <= n; ++i) cout << (color[i] == -1 ? 0 : color[i]); cout << endl;

	return 0;
}
