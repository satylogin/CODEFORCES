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

int A[100][100], B[100][100];

bool valid(int n, int m, int X[][100]) {
	bool correct = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j < m; ++j) correct &= (X[i][j] > X[i][j-1]);
	}
	for (int j = 0; j < m; ++j) {
		for (int i = 1; i < n; ++i) correct &= (X[i][j] > X[i-1][j]);
	}
	return correct;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n, m, i, j, k, x, y, z;
	cin >> n >> m;
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) cin >> A[i][j];
	for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) cin >> B[i][j];
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (A[i][j] > B[i][j]) swap(A[i][j], B[i][j]);
		}
	}
	if (valid(n, m, A) && valid(n, m, B)) cout << "Possible" << endl;
	else cout << "Impossible" << endl;
 
	return 0;
}
