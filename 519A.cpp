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

char str[100][100];
map <char, int> mp1, mp2;
int main()
{
	int a, b, i, j;
	for (i = 0; i < 8; ++i) cin >> str[i];
	a = b = 0;
	mp1['q'] = 9; mp1['r'] = 5; mp1['b'] = 3; mp1['n'] = 3; mp1['p'] = 1;
	mp2['Q'] = 9; mp2['R'] = 5; mp2['B'] = 3; mp2['N'] = 3; mp2['P'] = 1;
	for (i = 0; i < 8; ++i) {
		for (j = 0; j < 8; ++j) {
			if (mp1.find(str[i][j]) != mp1.end()) a += mp1[str[i][j]];
			if (mp2.find(str[i][j]) != mp2.end()) b += mp2[str[i][j]];
		}
	}

	if (a > b) cout << "Black" << endl;
	else if (a < b) cout << "White" << endl;
	else cout << "Draw" << endl;

	return 0;
}
