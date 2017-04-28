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
	int n;
	cin >> n;
	ld a, b, c;
	a = n * 100;
	b = 0;
	while (n--) {
		cin >> c;
		b += c;
	}
	printf("%.10LF\n", b*100/a);

	return 0;
}
