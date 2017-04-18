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

char str[100005];
int l[100005][2], r[100005][2];

int main()
{
	int n, i, j, k, a, b, c, x, y, z, p, q;
	cin >> n;
	scanf("%s", &str[1]);

	for (i = 1; i <= n; ++i) {
		if (str[i] == '0') {
			l[i][0] = 1 + l[i-1][1];
			l[i][1] = l[i-1][1];
		} else {
			l[i][1] = 1 + l[i-1][0];
			l[i][0] = l[i-1][0];
		}
	}
	z = max(l[n][0], l[n][1]);

	for (i = n; i > 0; --i) {
		if (str[i] == '0') {
			r[i][0] = r[i+1][1] + 1;
			r[i][1] = r[i+1][1];
		} else {
			r[i][1] = r[i+1][0] + 1;
			r[i][0] = r[i+1][0];
		}
	}

	x = 1;
	int ans = z;
	for (i = 2; i <= n; ++i) {
		if (str[i] == str[i-1]) {
			for (j = x; j < i; ++j) {
				if (str[j] == '0') str[j] = '1';
				else str[j] = '0';
			}
			
			a = 0; p = q = 0;
			for (j = x; j < i; ++j) {
				if (str[j] == a+'0') p++, a ^= 1;
			}

			ans = max(ans, l[x-1][1] + p + r[i][a]);
			
			a = 1;
			for (j = x; j < i; ++j) {
				if (str[j] == a+'0') q++, a ^= 1;
			}

			ans = max(ans, l[x-1][0] + q + r[i][a]);

			x = i;
		}
	}

	cout << ans << endl;

	return 0;
}
