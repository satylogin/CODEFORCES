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

set <int> se;

int main()
{
	int n = 4, x;
	while (n--) cin >> x, se.insert(x);
	cout << 4-se.size() << endl;

	return 0;
}
