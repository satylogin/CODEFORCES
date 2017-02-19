#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int e[300001], mark[100001], lev[300001], f[100001];
vector <int> v[100001], le[100001];
map <pair<int, int>, int> mp;
int ans[100001], id, par[100001], tree[1000001];
int ct[100001], cnt[100001];
queue <int> q;

void euler(int x, int l, int p)
{
	mark[x] = 1;
	e[++id] = x;
	lev[id] = l;
	f[x] = id;
	par[x] = p;
	le[l].pb(x);

	for (int i = 0; i < v[x].size(); ++i) {
		if (mark[v[x][i]] == 0) {
			euler(v[x][i], l+1, x);
			e[++id] = x;
			lev[id] = l;
		}
	}
}

void make_tree(int n, int start, int end)
{
	if (start == end) {
		tree[n] = start;
		return;
	}

	int mid = (start + end) >> 1;
	make_tree(n<<1, start, mid);
	make_tree(n<<1|1, mid+1, end);
	tree[n] = (lev[tree[n<<1]] < lev[tree[n<<1|1]]) ? tree[n<<1] : tree[n<<1|1];
}

int query(int n, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l) {
		return 0;
	}

	if (start >= l && end <= r) {
		return tree[n];
	}

	int mid = (start + end) >> 1;
	int a = query(n<<1, start, mid, l, r);
	int b = query(n<<1|1, mid+1, end, l, r);
	return (lev[a] < lev[b]) ? a : b;
}

int main()
{
	int n, m, i, j, k, x, y, a, b;
	cin >> n;
	for (i = 1; i < n; ++i) {
		cin >> x >> y;
		v[x].pb(y);
		v[y].pb(x);
		mp[mkp(x, y)] = mp[mkp(y, x)] = i;
	}

	euler(1, 1, 0);
	lev[0] = MOD;
	make_tree(1, 1, id);

	cin >> m;
	while (m--) {
		cin >> x >> y;
		cnt[x] += 1;
		cnt[y] += 1;
		if (f[x] > f[y]) {
			swap(x, y);	
		}
		a = query(1, 1, id, f[x], f[y]);
		a = e[a];
		//cout << x << " " << y << " " << a << endl;
		ct[a] += 2;
	}

	memset(mark, 0, sizeof(mark));
	for (i = 2; i <= n; ++i) {
		if (v[i].size() == 1) {
			q.push(i);
			mark[i] = 1;
		}
	}

	for (i = n; i > 1; --i) {
		for (j = 0; j < le[i].size(); ++j) {
			x = le[i][j];
			y = par[x];
			a = mp[mkp(x, y)];
			//cout << x << " " << y << " " << a << endl;
			ans[a] += cnt[x] - ct[x];
			cnt[y] += cnt[x] - ct[x];
		}
	}	

	for (i = 1; i < n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}
