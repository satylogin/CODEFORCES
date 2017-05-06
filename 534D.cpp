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

vector <int> v[200001];
int len[200001];
multiset <int> se[3];
multiset <int> :: iterator it;
int ans[2000001];

int main()
{
	int a, b, c, n, i, j, k, x, y, z;
	sci(n);

	for (i = 1; i <= n; ++i) {
		sci(x);
		se[x%3].insert(x);
		v[x].pb(i);
	}

	y = 0;
	for (i = 0; i < n; ++i) {
		x = i%3;
		while (y >= 0 && se[x].find(y) == se[x].end()) {
			y -= 3;
		}
		if (y < 0) {
			cout << "Impossible" << endl;
			return 0;
		}
		a = *se[x].find(y);
		se[x].erase(se[x].find(y));
		y++;
		ans[i] = v[a][len[a]++];
	}

	cout << "Possible" << endl;
	for (i = 0; i < n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");

	return 0;
}
