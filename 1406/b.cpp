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

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, i, j;
		cin >> n;
		vector<int> A(n);
		for (i = 0; i < n; ++i) cin >> A[i];
		sort(A.begin(), A.end());
		ll ans = LLONG_MIN, tmp = 1;
		for (int l = 5, r = 0; l >= 0; --l, ++r) {
			tmp = 1;
			for (int i = 0; i < l; ++i) tmp *= A[i];
			for (int i = n-1; i >= n-r; --i) tmp *= A[i];
			ans = max(ans, tmp);
		}
		cout << ans << endl;
	}

	return 0;
}
