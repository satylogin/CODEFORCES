#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n, k, i;
	vector<int> A(101);
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (i = 1; i <= n; ++i) cin >> A[i];
		int distinct = 1;
		for (i = 2; i <= n; ++i) {
			distinct += (A[i] != A[i-1]);
		}
		if (k == 1) {
			cout << (distinct == 1 ? 1 : -1) << endl;
			continue;
		}
		distinct -= min(distinct, k);
		int ans = 1 + (distinct + k - 2) / (k - 1);
		cout << ans << endl;
	}

	return 0;
}
