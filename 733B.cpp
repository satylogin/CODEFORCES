#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int l[100001], r[100001];

int main()
{
	int i, j, k, sl, sr, n;
	sl = sr = j = 0;
	cin >> n;

	for (i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
		sl += l[i];
		sr += r[i];
	}

	k = abs(sl - sr);

	for (i = 1; i <= n; ++i) {
		sl -= l[i];
		sr -= r[i];
		sl += r[i];
		sr += l[i];
		if (abs(sl-sr) > k) {
			k = abs(sl-sr);
			j = i;
		}
		sl -= r[i];
		sl += l[i];
		sr -= l[i];
		sr += r[i];
	}

	cout << j << endl;

	return 0;
}
