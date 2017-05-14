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

int mark[30];
char str[100000];

int main()
{
	int n, i, j, k;
	cin >> n >> str;
	k = 0;
	for (i = 0; str[i]; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] - 'A' + 'a';
		}
		if (!mark[str[i]-'a']) k++;
		mark[str[i]-'a'] = 1;
	}
	if (k == 26) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
