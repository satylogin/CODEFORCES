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

int pr[1000];
vector <int> v;

int main()
{
	int i, j, k, n, m;
	for (i = 2; i <= 100; ++i) {
		if (pr[i] == 0) {
			v.pb(i);
			for (j = i*i; j <= 100; j += i) 
				pr[j] = 1;
		}
	}

	cin >> n >> m;
	int x = v[upper_bound(v.begin(), v.end(), n) - v.begin()];
	if (x == m) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
