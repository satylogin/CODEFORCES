#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int main()
{
	string s[101];
	int n, i, a, b, j;
	cin >> n;
	for (i = 0; i < n; ++i) cin >> s[i];
	a = 0;
	for (i = 0; i < n; ++i) {
		b = 0;
		for (j = i; j < n; ++j) {
			if (s[i] == s[j]) b++;
		}
		a = max(a, b);
	}
	cout << a << endl;

	return 0;
}
