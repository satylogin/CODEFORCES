#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

const int N = 1e5;

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int n, i, j;
	vector<int> A(N), ans(N, -1);
	
	cin >> n;
	for (i = 0; i < n; ++i) cin >> A[i];
	sort(A.begin(), A.begin() + n);
	for (i = n-1, j = n-1; i >= 0 and j >= 0; i -= 2, j -= 1) {
		ans[i] = A[j];
		A[j] = -1;
	}

	int cnt = 0;
	for (i = 0, j = 0; i < n; ++i) {
		if (i > 0 and i < n-1 and ans[i] == -1 and A[j] < ans[i-1] and A[j] < ans[i+1]) {
			ans[i] = A[j++];
			cnt++;
		}
	}
	for (i = 0; i < n; ++i) if (ans[i] == -1) ans[i] = A[j++];
	cout << cnt << endl;
	for (i = 0; i < n; ++i) cout << ans[i] << " "; cout << endl;

	return 0;
}
