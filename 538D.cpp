#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

char str[100][100], ans[1000][1000], re[100][100];

int main()
{
	int n, i, j, k, a, b, c, x, y, z, l1, xi, xj, m;
	cin >> n;
	m = n+n-1;
	for (i = 0; i < n; ++i) {
		cin >> str[i];
	}

	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			ans[i][j] = 'x';
		}
	}

	x = n-1;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (str[i][j] == 'o') {
				for (xi = 0; xi < n; ++xi) {
					for (xj = 0; xj < n; ++xj) {
						if (str[xi][xj] == '.') {
							a = xi - i; b = xj - j;
							if (n+a >= 0 && n+b >= 0) {
								ans[x+a][x+b] = '.';
							}
						}
					}
				}
			}
		}
	}

	ans[x][x] = 'o';
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			re[i][j] = '.';
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (str[i][j] == 'o') {
				re[i][j] = 'o';
				for (xi = 0; xi < m; ++xi) {
					for (xj = 0; xj < m; ++xj) {
						if (ans[xi][xj] == 'x') {
							a = xi - x; b = xj - x;
							if (i+a >= 0 && i+a < n && j+b >= 0 && j+b < n && re[i+a][j+b] != 'o') {
								re[i+a][j+b] = 'x';
							}
						}
					}
				}
			}
		}
	}
/*
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			cout << re[i][j];
		} cout << endl;
	}
*/
	int fg = 1;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (str[i][j] != re[i][j]) {
				fg = 0; break;
			}
		}
	}

	if (fg == 0) {
		cout << "NO" << endl; return 0;
	}

	cout << "YES" << endl;
	for (i = 0; i < m; ++i) {
		for (j = 0; j < m; ++j) {
			putchar(ans[i][j]);
		}
		puts("");
	}

	return 0;
}
