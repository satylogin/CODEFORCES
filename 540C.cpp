#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

#define c1 (a >= 0 && a < n && b >= 0 && b < m && str[a][b] == '.')
#define c2 (a >= 0 && a < n && b >= 0 && b < m && str[a][b] == 'X' && a == xf && b == yf)

char str[600][600];
int mark[600][600];
int n, m, xf, yf;

void dfs(int x, int y)
{
	//cout << x << " " << y << endl;
	int a, b;
	a = x-1; b = y;
	if c1 {
		str[a][b] = 'X';
		dfs(a, b);
	} else if c2 {
		cout << "YES" << endl;
		exit(0);
	}
	a = x+1; b = y;
	if c1 {
		str[a][b] = 'X';
		dfs(a, b);
	} else if c2 {
		cout << "YES" << endl;
		exit(0);
	}
	a = x; b = y-1;
	if c1 {
		str[a][b] = 'X';
		dfs(a, b);
	} else if c2 {
		cout << "YES" << endl;
		exit(0);
	}
	a = x; b = y+1;
	if c1 {
		str[a][b] = 'X';
		dfs(a, b);
	} else if c2 {
		cout << "YES" << endl;
		exit(0);
	}
}

int main()
{
	int i, j, k, a, b, x, y, xi, yi;
	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> str[i];
	}
	cin >> xi >> yi >> xf >> yf;
	xi--; yi--; xf--; yf--;
	dfs(xi, yi);
	cout << "NO" << endl;

	return 0;
}
