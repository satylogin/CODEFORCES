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

int gcd(int x, int y) {
	return (y == 0 ? x : gcd(y, x % y));
}

int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int t, n;
	vector<int> A(1000);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> A[i];
		int idx = distance(A.begin(), max_element(A.begin(), A.begin() + n));
		swap(A[0], A[idx]);
		int g = A[0];
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (gcd(g, A[j]) > gcd(g, A[i])) {
					swap(A[i], A[j]);
				}
			}
			g = gcd(g, A[i]);
		}
		for (int i = 0; i < n; ++i) cout << A[i] << " "; cout << endl;
	}

	return 0;
}
