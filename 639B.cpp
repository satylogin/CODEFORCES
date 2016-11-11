#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int main()
{
	int n, cur, prev, d, h, i, j, k, x, y;

	cin >> n >> d >> h;

	if (d > 2*h || d < h) {
		cout << -1 << endl;
		return 0;
	}

	if (d == 1 && h == 1 && n > 2) {
		cout << -1 << endl;
		return 0;
	}

	i = 1;
	prev = 1;
	cur = 2;
	x = 1;
	while (x <= h) {
		printf("%d %d\n", prev, cur);
		prev = cur;
		cur += 1;
		x += 1;
	}

	if (d > h) {
		h = d - h;
		j = 1;
	} else {
		h = 1;
		j = 2;
	}
	while (cur <= n) {
		prev = j;
		x = 1;
		while (x <= h && cur <= n) {
			printf("%d %d\n", prev, cur);
			prev = cur;
			cur += 1;
			x += 1;
		}
	}

	return 0;
}
