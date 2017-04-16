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

queue <int> q1, q2;

int main()
{
	int n, i, j, k, a, b, c;
	c = 0;
	cin >> n;
	cin >> a;
	int x = 0;
	while (a--) cin >> k, q1.push(k);
	cin >> b;
	while (b--) cin >> k, q2.push(k);
	while (!q1.empty() && !q2.empty()) {
		c++;
		if (c > 1000000) {
			cout << -1 << endl;
			return 0;
		}
		a = q1.front();
		b = q2.front();
		q1.pop(), q2.pop();
		if (a > b) {
			q1.push(b);
			q1.push(a);
		} else if (a < b) {
			q2.push(a);
			q2.push(b);
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << c << " ";
	if (q1.empty()) cout << 2 << endl;
	else cout << 1 << endl;

	return 0;
}
