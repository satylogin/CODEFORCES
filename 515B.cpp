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

int a[101], b[101];

int main()
{
	int n, m, i, j, k, x, y, z;
	cin >> n >> m;
	cin >> x;
	while (x--) cin >> y, a[y] = 1;
	cin >> x;
	while (x--) cin >> y, b[y] = 1;

	z = n+m;
	for (i = 0; i < 10000000; ++i) {
		x = i%n; y = i%m;
		a[x] = b[y] = (a[x] | b[y]);
	}	

	for (i = 0; i < n; ++i) {
		if (!a[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	for (i = 0; i < m; ++i) {
		if (!b[i]) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;

	return 0;
}
