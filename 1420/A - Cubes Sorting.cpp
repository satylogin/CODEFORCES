#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int n, t, i;
	vector<int> A(50004);
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) cin >> A[i];
		bool reverse_sorted = true;
		for (i = 0; i < n-1; ++i) {
			reverse_sorted &= (A[i] > A[i+1]);
		}
		if (reverse_sorted) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	return 0;
}
