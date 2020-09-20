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
#define eps 1e-9
#define PI 3.14159265

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n, i, e, o, on, en;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> s;
		o = (n + 1) / 2;
		e = n - o;
		on = en = 0;
		for (i = 0; i < n; ++i) {
			if (i%2) en += ((s[i]-'0')%2);
			else on += ((s[i]-'0')%2);
		}
		if (o > e && on > 0) cout << 1 << endl;
		else if (o == e && en == e) cout << 1 << endl;
		else cout << 2 << endl;
	}

	return 0;
}
