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
	ll a, b, c, x;
	c = 0;
	cin >> a >> b;
	while (a > 0 && b > 0) {
		if (b > a) swap(a, b);
		c += (a/b);
		a %= b;
	}
	cout << c << endl;

	return 0;
}
