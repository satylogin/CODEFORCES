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

struct Centroid {
	vector<vector<int>> connection;
	vector<int> size;
	vector<int> centroids;
	vector<int> parent;
	int max_size;

	Centroid(int n) {
		size.resize(n+1, 1);
		connection.resize(n+1);
		parent.resize(n+1, 0);
		max_size = INT_MAX;
	}

	void add_edge(int x, int y) {
		connection[x].push_back(y);
		connection[y].push_back(x);
	}

	int find_size(int x, int p) {
		parent[x] = p;
		for (int conn: connection[x]) {
			if (conn == p) continue;
			size[x] += find_size(conn, x);
		}

		return size[x];
	}

	void check_centroid(int x, int p) {
		int mx = 0;
		for (int conn: connection[x]) {
			if (conn == p) mx = max(mx, size[1] - size[x]);
			else mx = max(mx, size[conn]);
		}
		if (mx == max_size) {
			centroids.push_back(x);
		} else if (mx < max_size) {
			max_size = mx;
			centroids.clear();
			centroids.push_back(x);
		}
	}

	void find_centroids(int x, int p) {
		check_centroid(x, p);
		for (int conn: connection[x]) {
			if (conn != p) find_centroids(conn, x);
		}
	}

	void print_solution() {
		find_size(1, 0);
		find_centroids(1, 0);
		int n = centroids.size();
		int x1 = -1, x2 = -1, y1 = -1;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j) continue;
				for (int conn_i: connection[centroids[i]]) {
					if (conn_i != centroids[j]) {
						x1 = centroids[i];
						y1 = conn_i;
						x2 = centroids[j];
						break;
					}
				}
				if (x1 != -1) break;
			}
			if (x1 != -1) break;
		}
		if (x1 == -1) {
			x1 = x2 = 1;
			y1 = connection[1][0];
		}
		cout << x1 << " " << y1 << endl;
		cout << x2 << " " << y1 << endl;
	}
};

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n, i, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		Centroid centroid(n);
		for (i = 1; i < n; ++i) {
			cin >> x >> y;
			centroid.add_edge(x, y);
		}
		centroid.print_solution();
	}

	return 0;
}
