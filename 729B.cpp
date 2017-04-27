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

int arr[1001][1001], a[1001][1001], b[1001][1001];

int main()
{
	int n, m, i, j, k, ans = 0;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> arr[i][j];
			a[i][j] = b[i][j] = arr[i][j];
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (j != 0) a[i][j] += a[i][j-1];
			if (i != 0) b[i][j] += b[i-1][j];
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			if (arr[i][j]) continue;
			ans += ((b[n-1][j] - b[i][j]) > 0);
			ans += ((b[i][j]) > 0);
			ans += ((a[i][m-1] - a[i][j]) > 0);
			ans += ((a[i][j]) > 0);
		}
	}

	cout << ans << endl;

	return 0;
}
