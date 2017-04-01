#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

ld dp[101][101][101];

int main()
{
	int r, s, p;
	cin >> r >> s >> p;
	dp[r][s][p] = 1;
	
	for (int i = r + p + s; i > 0; --i) {
		for (int j = r; j >= 0; --j) {
			for (int k = s; k >= 0; --k) {
				int l = i - j - k;
				if (l < 0 || l > p) continue;
				if (j == 0 && k == 0) continue;
				if (k == 0 && l == 0) continue;
				if (l == 0 && j == 0) continue;
				ld cur = dp[j][k][l];
				ld w1 = j * k;
				ld w2 = k * l;
				ld w3 = l * j;
				ld ways = w1 + w2 + w3;
				if (j > 0) dp[j-1][k][l] += cur * w3 / ways;
				if (k > 0) dp[j][k-1][l] += cur * w1 / ways;
				if (l > 0) dp[j][k][l-1] += cur * w2 / ways;
				//cout << j << " " << k << " " << l << " " << dp[j][k][l] << endl;
			}
		}	
	}

	ld a, b, c;
	a = b = c = 0.0;

	for (int i = 1; i <= r; ++i) a += dp[i][0][0];
	for (int i = 1; i <= s; ++i) b += dp[0][i][0];
	for (int i = 1; i <= p; ++i) c += dp[0][0][i];

	printf("%.9Lf %.9Lf %.9Lf\n", a, b, c);

	return 0;
}
