#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define EPS 1e-9
#define PI 3.14159265

class Solution {
public:
	long long ans, n;
	vector<long long> A;

	Solution(int n): n(n) {
		ans = 0;
		A.resize(n+2);
		fill(A.begin(), A.end(), 0);
	}

	void insert(int i) {
		if (i < 1 or i > n) return;
		if ((A[i-1] == 0 or A[i] > A[i-1]) and (A[i+1] == 0 or A[i] > A[i+1])) ans += A[i];
		else if (A[i] < A[i-1] and A[i] < A[i+1]) ans -= A[i];
	}

	void erase(int i) {
		if (i < 1 or i > n) return;
		if ((A[i-1] == 0 or A[i] > A[i-1]) and (A[i+1] == 0 or A[i] > A[i+1])) ans -= A[i];
		else if (A[i] < A[i-1] and A[i] < A[i+1]) ans += A[i];
	}
};

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	long long t, n, q, i, x, y;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		Solution sol(n);
		for (i = 1; i <= n; ++i) cin >> sol.A[i];
		for (i = 1; i <= n; ++i) {
			sol.insert(i);
		}
		cout << sol.ans << endl;
		while (q--) {
			cin >> x >> y;
			set<long long> erased;
			for (i = -1; i <= 1; ++i) {
				long long idx = x + i;
				if (!erased.count(idx)) {
					sol.erase(idx);
					erased.insert(idx);
				}
				idx = y + i;
				if (!erased.count(idx)) {
					sol.erase(idx);
					erased.insert(idx);
				}
			}
			swap(sol.A[x], sol.A[y]);
			erased.clear();
			for (i = -1; i <= 1; ++i) {
				long long idx = x + i;
				if (!erased.count(idx)) {
					sol.insert(idx);
					erased.insert(idx);
				}
				idx = y + i;
				if (!erased.count(idx)) {
					sol.insert(idx);
					erased.insert(idx);
				}
			}
			cout << sol.ans << endl;
		}
	}

	return 0;
}
