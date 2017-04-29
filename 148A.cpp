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

int a[100001], b[100001];

int main()
{
	int x = 0, y = 0, i, j, n;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		if (a[i]) x++;
		if (b[i]) y++;
	}
	x = min(x, n-x);
	y = min(y, n-y);
	cout << x+y << endl;

	return 0;
}
