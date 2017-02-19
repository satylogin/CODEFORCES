#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

vector <int> v[100001];
vector <int> lev[100001];
int ar[100001], de[100001], tim, lv[100001];
int par[100001];

void dfs(int x, int l)
{
	lev[l].pb(x);
	ar[x] = ++tim;
	lv[x] = l;
	for (int i = 0; i < v[x].size(); ++i) {
		dfs(v[x][i], l+1);
	}
	de[x] = ++tim;
}

int main()
{
	int n, m, l, i, j, k, x, y, a, b, c;
	int start, mid, end, idx;

	scan(n);
	for (i = 1; i <= n; ++i) {
		scan(x);
		par[i] = x;
		v[x].pb(i);
	}

	for (i = 1; i <= n; ++i) {
		if (par[i] == 0) {
			dfs(i, 1);
		}
	}

	scan(m);
	while (m--) {
		scan(x); scan(b);
		l = lv[x];
		l -= b;
		if (l < 1) {
			printf("0 ");
			continue;
		} 
		start = 0;
		end = lev[l].size() - 1;
		while (start <= end) {
			mid = (start + end) >> 1;
			y = lev[l][mid];
			if (ar[y] <= ar[x]) {
				idx = y;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		x = idx;
		l += b;
		a = b = -1;
		start = 0;
		end = lev[l].size() - 1;
		while (start <= end) {
			mid = (start + end) >> 1;
			y = lev[l][mid];
			if (ar[y] >= ar[x]) {
				a = mid;
				end = mid - 1;
			} else {
				start = mid + 1;
			}
		}
		start = 0;
		end = lev[l].size() - 1;
		while (start <= end) {
			mid = (start + end) >> 1;
			y = lev[l][mid];
			if (de[y] <= de[x]) {
				b = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		//cout << endl << a << " " << b << endl;
		if (b != -1 && a != -1 && b-a > 0) {
			printf("%d ", b-a);
		} else {
			printf("0 ");
		}
	}
	puts("");

	return 0;
}
