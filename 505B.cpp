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

int par[101][101];

int find_par(int c, int x)
{
	if (x == par[c][x]) return x;
	return (par[c][x] = find_par(c, par[c][x]));
}

void uni(int c, int x, int y)
{
	int px = find_par(c, x);
	int py = find_par(c, y);
	if (px != py) par[c][px] = py;
}

int main()
{
	int n, m, i, j, k, x, y, a, b, c;
	cin >> n >> m;
	for (i = 1; i <= 100; ++i) {
		for (j = 1; j <= 100; ++j) {
			par[i][j] = j;
		}
	}

	while (m--) {
		cin >> a >> b >> c;
		uni(c, a, b);
	}
	cin >> c;
	while (c--) {
		cin >> a >> b;
		k = 0;
		for (i = 1; i <= 100; ++i) {
			x = find_par(i, a);
			y = find_par(i, b);
			k += (x == y);
		}
		cout << k << endl;
	}

	return 0;
}
