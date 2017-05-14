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

char str[1000001];
int mark[30];

ll pow_(ll a, ll b)
{
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = (ans * a) % MOD;
		}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ans;
}

int main()
{
	int n, i, j, k;
	sci(n);
	scanf("%s", str);
	for (i = 0; str[i]; ++i) mark[str[i]-'A']++;
	k = 0, j = 0;
	for (i = 0; i < 26; ++i) {
		if (mark[i] > k) k = mark[i], j = 1;
		else if (mark[i] == k) j++;
	}
	cout << pow_((ll)j, (ll)n) << endl;

	return 0;
}
