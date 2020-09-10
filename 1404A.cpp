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

class BITRangeUpdatePointQuery {
private:
	vector<int> tree;
	int n;

	void insert(int x, int v) {
		for (; x <= n; x += (x&-x)) {
			tree[x] += v;
		}
	}

public:
	BITRangeUpdatePointQuery(int n) {
		this-> n = n;
		tree.resize(n+1, 0);
	}

	void update(int r) {
		insert(1, 1);
		insert(r+1, -1);
	}

	int query(int x) {
		int ans = 0;
		for (; x > 0; x -= (x&-x)) {
			ans += tree[x];
		}

		return ans;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n, q, l, r;
	cin >> n >> q;

	vector<int> A(n+1);
	vector<vector<pair<int, int>>> query(n+1); 
	vector<int> ans(q);
	BITRangeUpdatePointQuery bit(n);

	for (int i = 1; i <= n; ++i) cin >> A[i];
	for (int i = 0; i < q; ++i) {
		cin >> l >> r;
		query[n-r].pb(mkp(1+l, i));
	}

	for (int r = 1; r <= n; ++r) {
		int x = r - A[r];
		if (x >= 0) {
			int start = 1, end = r, idx = -1;
			while (start <= end) {
				int mid = (start + end) >> 1;
				if (bit.query(mid) >= x) {
					idx = mid;
					start = mid + 1;
				} else {
					end = mid - 1;
				}
			}
			if (idx != -1) bit.update(idx);
		}
		for (pair<int, int> &it: query[r]) {
			ans[it.sc] = bit.query(it.fi);
		}
	}

	for (int i = 0; i < q; ++i) cout << ans[i] << endl;
 
	return 0;
}
