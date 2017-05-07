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

int a1[1000], a2[1000];

int main()
{
	int n, m, i, j, k, a, b, c;
	c = 0;
	a = 0;

	cin >> n; for (i = 0; i < n; ++i) cin >> a1[i];
	cin >> m; for (i = 0; i < m; ++i) cin >> a2[i];
	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) 
			if (a2[j]%a1[i] == 0) {
				b = a2[j] / a1[i];
				if (b > a) a = b, c = 1;
				else if (b == a) c++;
			}
	cout << c << endl;

	return 0;
}
