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

int n, m;
char str[2100][2100];
int mark[2100][2100];

void bfs(int x, int y)
{
	if (x < 1 || x >= n || y < 1 || y >= m) return;

	int i, j, k = 0;
	for (i = 0; i <= 1; ++i) {
		for (j = 0; j <= 1; ++j) {
			if (str[x+i][y+j] == '*') k++;
		}
	}

	if (k == 1) {
		for (i = 0; i <= 1; ++i) {
			for (j = 0; j <= 1; ++j) {
				str[x+i][y+j] = '.';
			}
		}

		for (i = -1; i <= 2; ++i) {
			for (j = -1; j <= 2; ++j) {
				bfs(x+i, y+j);
			}
		}
	}
}

int main()
{
	int i, j, k;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		scanf("%s", &str[i][1]);
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			bfs(i, j);
		}
	}

	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= m; ++j) {
			putchar(str[i][j]);
		}
		puts("");
	}

	return 0;
}
