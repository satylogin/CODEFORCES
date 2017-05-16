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

ll ans[101][101];

int main()
{
	int n, i, j, k, x1, x2, y1, y2;
	cin >> n;
	while (n--) {
		cin >> x1 >> y1 >> x2 >> y2;
		for (i = x1; i <= x2; ++i) {
			for (j = y1; j <= y2; ++j) {
				ans[i][j]++;
			}
		}
	}	

	ll val = 0;
	for (i = 1; i <= 100; ++i) {
		for (j = 1; j <= 100; ++j) {
			val += ans[i][j];
		}
	}

	cout << val << endl;

	return 0;
}
