#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int a[200], b[200];

int main()
{
	int n, s, i, j, k;
	cin >> n >> s;
	k = s;
	if (n == 1 && s == 0) {
		cout << 0 << " " << 0 << endl;
		return 0;
	} else if (n >= 1 && s == 0) {
		cout << -1 << " " << -1 << endl;
		return 0;
	}
	a[1] = 1;
	s--;
	if (s < 0) {
		cout << -1 << " ";
	} else {
		for (i = n; i >= 1; --i) {
			if (i != 1) {
				if (s >= 9) {
					s -= 9;
					a[i] = 9;
				} else {
					a[i] = s;
					s = 0;
				}
			} else if (s >= 8) {
				a[i] = 9;
				s -= 8;
			} else {
				a[i] += s;
				s = 0;
			}
		}
		if (s == 0) {
			for (j = 1; j <= n; ++j) cout << a[j];
			cout << " ";
		} else {
			cout << -1 << " ";
		}
	}
	s = k;
	for (i = 1; i <= n; ++i) {
		if (s >= 9) {
			b[i] = 9;
			s -= 9;
		} else {
			b[i] = s;
			s = 0;
		}
	}
	if (s == 0) {
		for (j = 1; j <= n; ++j) cout << b[j]; 
		cout << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
