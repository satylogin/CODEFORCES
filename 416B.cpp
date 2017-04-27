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

int arr[50001][5], ans[50001];

int main()
{
	int n, m, i, j, k, x;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < m; ++j) {
			cin >> arr[i][j];
		}
	}

	for (j = 0; j < m; ++j) {
		k = 0;
		for (i = 0; i < n; ++i) {
			x = max(k, ans[i]);
			ans[i] = x + arr[i][j];
			k = ans[i];
		}
	}

	for (i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}
