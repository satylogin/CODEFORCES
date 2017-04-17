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

int arr[501][501], ans[501];

int main()
{
	int n, m, q, i, j, x, y;
	cin >> n >> m >> q;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			cin >> arr[i][j];
		}	
	}

	for (i = 1; i <= n; ++i) {
		x = 0;
		for (j = 1; j <= m; ++j) {
			if (arr[i][j] == 1) x++;
			else x = 0;
			ans[i] = max(ans[i], x);
		}
	}

	while (q--) {
		cin >> i >> j;
		arr[i][j] ^= 1;
		ans[i] = 0;
		x = 0;
		for (j = 1; j <= m; ++j) {
			if (arr[i][j] == 1) x++;
			else x = 0;
			ans[i] = max(ans[i], x);
		}
		x = 0;
		for (i = 1; i <= n; ++i) x = max(x, ans[i]);
		cout << x << endl;
	}

	return 0;
}
