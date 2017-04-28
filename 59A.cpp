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

char str[1000];

int main()
{
	int i, a, b;
	cin >> str;
	a = b = 0;
	for (i = 0; str[i]; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') a++;
		else b++;
	}
	if (a >= b) {
		for (i = 0; str[i]; ++i) {
			putchar(tolower(str[i]));
		} puts("");
	} else {
		for (i = 0; str[i]; ++i) {
			putchar(toupper(str[i]));
		} puts("");
	}

	return 0;
}
