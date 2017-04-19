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

vector <int> v[100001];
set <int> se[100001];
set <int> :: iterator it;
stack <pii > st;

int mark[1000][1000];

int main()
{
	int c, n, k, i, j, x, y, a, b;

	cin >> k;
	if (k == 1) {
		cout << "YES" << endl;
		cout << "2 1" << endl;
		cout << "1 2" << endl;
		return 0;
	}

	if (!(k&1)) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;
	n = k+2;
	a = 1;
	while (a == 1) {
		a = 0;
		for (i = 1; i <= n; ++i) {
			if (se[i].size() < k) {
				for (j = 1; j <= n; ++j) {
					x = (i+j) % n;
					if (x == 0) x = n;
					if (x == i) continue;
					if (se[x].find(i) != se[x].end()) continue;
					if (se[x].size() >= k) continue;
					se[i].insert(x);
					se[x].insert(i);
					a = 1;
					break;
				}
			}
		}
	}

	for (i = 1; i <= n; ++i) {
		if (se[i].size() < k) x = i;
	}

	for (i = 1; i <= n; ++i) {
		for (it = se[i].begin(); it != se[i].end(); ++it) {
			j = *it;
			if (mark[i][j] == 0) {
				mark[i][j] = mark[j][i] = 1;
				st.push(mkp(i, j));
			}
			if (mark[i+n][j+n] == 0) {
				mark[i+n][j+n] = mark[j+n][i+n] = 1;
				st.push(mkp(i+n, j+n));
			}
		}
	}
	st.push(mkp(x, x+n));
	mark[x][x+n] = mark[x+n][x] = 1;
	cout << n+n << " " << st.size() << endl;
	while (!st.empty()) {
		cout << st.top().first << " " << st.top().second << endl;
		st.pop();
	}

	return 0;
}
