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

char str[101][101];

int main()
{
	int n, k, i, j, c;
	c = 0;
	cin >> n >> k;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			str[i][j] = 'S';
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (c == k) break;
			if (i&1) {
				if (j&1) {
					str[i][j] = 'L';
					c++;
				}
			} else {
				if (!(j&1)) {
					str[i][j] = 'L';
					c++;
				}
			}
			if (c == k) break;
		}
		if (c == k) break;
	}
	if (c == k) {
		cout << "YES" << endl;
		for (i = 0; i < n; ++i) {
			for (j = 0; j < n; ++j) {
				putchar(str[i][j]);
			}
			puts("");
		}
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
