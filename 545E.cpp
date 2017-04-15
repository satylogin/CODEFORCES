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

#define piii pair <pll, pii >

ll par[1000001];
ll mark[1000001];
vector <pii > v[1000001];
map <pii, ll> mp;
vector <int> edg;
priority_queue <piii, vector<piii >, greater<piii > > pq;

void dij(int x)
{
	pq.push(mkp(mkp(0, 0), mkp(x, -1)));
	int i, j, z;
	ll y;
	while (!pq.empty()) {
		y = pq.top().first.first;
		x = pq.top().second.first;
		z = pq.top().second.second;
		pq.pop();
		if (mark[x]) continue;
		mark[x] = 1;
		if (z != -1) edg.pb(mp[mkp(x, z)]);
		for (i = 0; i < v[x].size(); ++i) {
			if (mark[v[x][i].first] == 0) {
				pq.push(mkp(mkp(y+v[x][i].second, v[x][i].second), mkp(v[x][i].first, x)));
			}
		}
	}
}

int main()
{
	int u, n, m, x, y, i, j, z;
	cin >> n >> m;
	for (i = 1; i <= m; ++i) {
		sci(x); sci(y); sci(z);
		v[x].pb(mkp(y, z));
		v[y].pb(mkp(x, z));
		mp[mkp(x, y)] = mp[mkp(y, x)] = i;
		par[i] = z;
	}
	cin >> u;
	dij(u);
	sort(edg.begin(), edg.end());
	ll sum = 0;
	for (i = 0; i < edg.size(); ++i) {
		sum += par[edg[i]];
	}
	cout << sum << endl;
	for (i = 0; i < edg.size(); ++i) {
		printf("%d ", edg[i]);
	} cout << endl;

	return 0;
}
