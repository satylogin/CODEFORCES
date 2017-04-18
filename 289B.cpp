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

int arr[10001];

int main()
{
	int n, m, d, i, j, k, x, y, z;
	cin >> n >> m >> d;
	x = n*m;
	for (i = 0; i < x; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);

	for (i = 1; i < x; ++i) {
		if ((arr[i]-arr[i-1])%d) {
			cout << -1 << endl;
			return 0;
		} 
	}

	int ans = MOD;
	for (i = 0; i < x; ++i) {
		y = 0;
		for (j = 0; j < x; ++j) {
			y += (abs(arr[i]-arr[j]) / d);
		}
		ans = min(ans, y);
	}
	cout << ans << endl;

	return 0;
}
