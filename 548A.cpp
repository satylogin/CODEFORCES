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

int main()
{
	string s;
	int i, j, k, n, x, y;
	cin >> s;
	cin >> k;
	n = s.size();
	if (n%k) {
		cout << "NO" << endl;
		return 0;
	}

	k = n/k;
	i = 0;
	while (i < n) {
		x = i;
		y = i+k-1;
		while (x < y) {
			if (s[x] != s[y]) {
				cout << "NO" << endl;
				return 0;
			}
			x++; y--;
		}
		i += k;
	}
	cout << "YES" << endl;

	return 0;
}
