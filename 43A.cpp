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

string str[1000];

int main()
{
	int n, i;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> str[i];
	}
	sort(str, str+n);
	int a = upper_bound(str, str + n, str[0]) - lower_bound(str, str+n, str[0]);
	int b = n - a;
	if (a > b) cout << str[0] << endl;
	else cout << str[n-1] << endl;

	return 0;
}
