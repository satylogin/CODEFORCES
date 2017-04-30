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
	int x, y, z, a, b, c;
	cin >> x >> y >> z;
	a = sqrt(x * z / y);
	b = sqrt(x * y / z);
	c = sqrt(y * z / x);
	cout << (a+b+c) * 4 << endl;

	return 0;
}
