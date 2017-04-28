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
	int i, len;
	cin >> str;
	len = strlen(str);
	i = 0;
	while (i < len) {
		if (str[i] == '.') {
			putchar('0');
			i++;
		} else {
			i++;
			if (str[i] == '.') putchar('1');
			else putchar('2');
			i++;
		}
	}
	puts("");

	return 0;
}
