#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n, x;
	vector<int> A(1000);

	cin >> t;
	while (t--) {
		cin >> n >> x;
		int abs_sum = 0, diff = 0;
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
			diff += (A[i] != x);
			abs_sum += (A[i] - x);
		}
		if (diff == 0) cout << 0 << endl;
		else if (abs_sum == 0 or diff != n) cout << 1 << endl;
		else cout << 2 << endl;
	}

	return 0;
}
