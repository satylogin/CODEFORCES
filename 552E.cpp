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

char str[100000];
ll ans[5001][5001];
int main()
{
	ll i, j, k, a, n, b, c, x, y, z, tmp;
	scanf("%s", str);
	n = strlen(str);

	for (i = 0; i < n; ++i) {
		if (!(str[i] >= '0' && str[i] <= '9')) continue;
		ans[i][i] = str[i]-'0';
		for (j = i+1; j < n; ++j) {
			if (!(str[j] >= '0' && str[j] <= '9')) continue;
			if (str[j-1] == '*') {
				k = j-1;
				while (k > i && str[k] == '*') k -= 2;
				x = 1;
				for (a = k+1; a <= j; a += 2) {
					x *= (str[a]-'0');
				}
				if (k-1 >= i) ans[i][j] = ans[i][k-1] + x;
				else ans[i][j] = x;
			} else {
				if (j-2 >= i) ans[i][j] = ans[i][j-2] + (str[j]-'0');
				else ans[i][j] = str[j]-'0';
			}	
		}
	}
	tmp = 0;

	for (i = 0; i < n; ++i) {
		if (!(str[i] >= '0' && str[i] <= '9')) continue;
		for (j = i; j < n; ++j) {
			if (!(str[j] >= '0' && str[j] <= '9')) continue;
			x = 1;
			for (k = i-1; k > 0; k -= 2) {
				if (str[k] == '*') x *= (str[k-1]-'0');
				else break;
			}
			y = 0;
			if (k > 0) y += ans[0][k-1];
			for (k = j+1; k < n; k += 2) {
				if (str[k] == '*') x *= (str[k+1]-'0');
				else break;
			}
			if (k+1 <= n-1) y += ans[k+1][n-1];
			tmp = max(tmp, y + x * ans[i][j]);
		}
	}

	cout << tmp << endl;

	return 0;
}
