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

int arr[20];

int main()
{
	int c, n, l, r, x, i, j, a, b, s, lim;

	cin >> n >> l >> r >> x;
	lim = (1<<n);
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	c = 0;
	for (i = 1; i < lim; ++i) {
		s = 0;
		a = MOD;
		b = 0;
		for (j = 0; j < n; ++j) {
			if (i&(1<<j)) {
				s += arr[j];
				a = min(a, arr[j]);
				b = max(b, arr[j]);
			}
		}
		if (s >= l && s <= r && (b-a >= x)) {
			c++;
		}
	}

	cout << c << endl;

	return 0;
}
