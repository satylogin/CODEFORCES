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

int dp1[100005], dp2[100005];
char str[100005];

int main()
{
	int n, k, i, j, a, b, c;
	cin >> n >> k;
	scanf("%s", &str[1]);

	for (i = 1; str[i]; ++i) {
		dp1[i] = dp1[i-1];
		dp2[i] = dp2[i-1];
		if (str[i] == 'b') dp1[i]++;
		if (str[i] == 'a') dp2[i]++;	
	}
	
	c = 0;
	for (i = 1; i <= n; ++i) {
		a = (&dp1[i]) - lower_bound(dp1, dp1+1+n, dp1[i]-k);
		b = (&dp2[i]) - lower_bound(dp2, dp2+1+n, dp2[i]-k);
		c = max(c, max(a, b));
	}	
	cout << c << endl;

	return 0;
}
