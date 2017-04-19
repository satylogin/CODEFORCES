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
#define se second

int col[100001];
int mark[100001];
set <int> se[100001];
int par[100001];
queue <int> q;
set <int> :: iterator it;

void dfs(int x, int p)
{
	mark[x] = 1;
	par[x] = p;
	for (it = se[x].begin(); it != se[x].end(); ++it) {
		if (!mark[*it]) {
			dfs(*it, x);
		}
	}
}

int main()
{
	int n, m, i, j, k, x, y, z;

	cin >> n;
	for (i = 1; i <= n; ++i) {
		par[i] = i;
	}

	for (i = 1; i < n; ++i) {
		cin >> x >> y;
		se[x].insert(y);
		se[y].insert(x);
	}

	for (i = 1; i <= n; ++i) cin >> col[i];

	for (i = 1; i <= n; ++i) {
		if (se[i].size() == 1) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		x = q.front();
		q.pop();
		if (col[x] == col[*se[x].begin()]) {
			se[*se[x].begin()].erase(x);
			if (se[*se[x].begin()].size() == 1) {
				q.push(*se[x].begin());
			}
			se[x].erase(se[x].begin());
		}
	}

	x = 0;
	for (i = 1; i <= n; ++i) {
		if (se[i].size() == 0) {
				x++;
				continue;
		}
		y = 0;
		for (it = se[i].begin(); it != se[i].end(); ++it) {
			if (se[*it].size() > 1) y = 1;
		}
		if (y == 0) {
			cout << "YES" << endl;
			cout << i << endl;
			return 0;
		}
	}

	if (x == n) {
		cout << "YES" << endl;
		cout << 1 << endl;
		return 0;
	}

	cout << "NO" << endl;

	return 0;
}
