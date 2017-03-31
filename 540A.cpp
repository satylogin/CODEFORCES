#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

char s1[1001], s2[1001];

int main()
{
	int n, i, j, ans = 0, a, b;
	cin >> n >> s1 >> s2;
	for (i = 0; i < n; ++i) {
		a = s1[i]-'0';
		b = s2[i]-'0';
		ans += min(abs(a-b), 10 - abs(a-b));
	}
	cout << ans << endl;

	return 0;
}
