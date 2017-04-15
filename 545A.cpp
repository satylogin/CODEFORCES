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

int mark[1001];

int main()
{
	int n, i, j, x, c;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			cin >> x;
			if (x == 1) {
				mark[i] = 1;
			} else if (x == 2) {
				mark[j] = 1;
			} else if (x == 3) {
				mark[i] = mark[j] = 1;
			}
		}
	}

	c = 0;
	for (i = 1; i <= n; ++i) if (!mark[i]) c++;
	cout << c << endl;
	if (c != 0) { for (i = 1; i <= n; ++i) if (!mark[i]) cout << i << " "; cout << endl; }

	return 0;
}
