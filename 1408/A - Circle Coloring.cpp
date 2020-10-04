#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define EPS 1e-9
#define PI 3.14159265

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, i, n;
	vector<int> A(100), B(100), C(100);

	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) {
			cin >> A[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> B[i];
		}
		for (i = 0; i < n; ++i) {
			cin >> C[i];
		}
		for (i = 0; i < n; ++i) {
			int x = A[i];
			if (x == A[(i - 1 + n) % n] or x == A[(i + 1) % n]) x = B[i];
			if (x == A[(i - 1 + n) % n] or x == A[(i + 1) % n]) x = C[i];
			A[i] = x;
		}
		for (i = 0; i < n; ++i) {
			cout << A[i] << " ";
		} cout << endl;
	}

	return 0;
}
