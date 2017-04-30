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

int main()
{
	int n, m, i, x, a = 0, b = 1;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		cin >> x;
		x = (x + m - 1) / m;
		if (x >= a) a = x, b = i;
	}
	cout << b << endl;

	return 0;
}
