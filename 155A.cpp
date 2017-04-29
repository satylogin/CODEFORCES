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
	int n, x, a, b, c;
	c = 0;
	cin >> n;
	n--;
	cin >> x;
	b = a = x;
	while (n--) {
		cin >> x;
		if (x < a) a = x, c++;
		if (x > b) b = x, c++;
	}
	cout << c << endl;

	return 0;
}
