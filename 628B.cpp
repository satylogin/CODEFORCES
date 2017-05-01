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

char str[1000000];

int main()
{
	int i, j, k, a, b, c;
	ll ans = 0;
	scanf("%s", str);
	for (i = 0; str[i]; ++i) {
		a = str[i] - '0';
		if (i == 0) b = 0;
		else b = 10 * (str[i-1]-'0');
		b = a + b;
		if (!(a%4)) ++ans;
		if (!(b%4)) ans += i;
	}
	printf("%lld\n", ans);

	return 0;
}
