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

#define N 3005

vector <int> v[N];
int dist[N][N];
queue <int> q;

int main()
{	
	int n, m, i, j, k, x, y, a, b;
	int s[2], t[2], l[2];

	cin >> n >> m;
	for (i = 0; i < m; ++i) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
	}

	memset(dist, -1, sizeof(dist));
	for (i = 1; i <= n; ++i) {
		dist[i][i] = 0;
		q.push(i);
		while (!q.empty()) {
			x = q.front();
			q.pop();
			for (j = 0; j < v[x].size(); ++j) {
				if (dist[i][v[x][j]] == -1) {
					dist[i][v[x][j]] = dist[i][x] + 1;
					q.push(v[x][j]);
				}
			}
		}
	}
	cin >> s[0] >> t[0] >> l[0];
	cin >> s[1] >> t[1] >> l[1];

	int ans = MOD;
	for (k = 0; k < 2; ++k) {
		swap(s[0], t[0]);
		for (i = 1; i <= n; ++i) {
			for (j = 1; j <= n; ++j) {
				x = dist[s[0]][i] + dist[i][j] + dist[j][t[0]];
				y = dist[s[1]][i] + dist[i][j] + dist[j][t[1]];
				if (x <= l[0] && y <= l[1]) {
					ans = min(ans, x+y-dist[i][j]);
				}
			}
		}
	}

	if (dist[s[0]][t[0]] <= l[0] && dist[s[1]][t[1]] <= l[1]) {
		ans = min(dist[s[0]][t[0]] + dist[s[1]][t[1]], ans);
	}

	if (ans > m) cout << -1 << endl;
	else cout << m-ans << endl;

	return 0;
}
