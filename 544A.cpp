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

int mark[30];

int main()
{
	int k, i, c;
	string str;
	cin >> k;
	cin >> str;
	c = 0;
	for (i = 0; str[i]; ++i) {
		if (mark[str[i] - 'a'] == 0) {
			c++;
		}
		mark[str[i]-'a'] = 1;
	}

	if (c < k) {
		cout << "NO" << endl; return 0;
	}
	cout << "YES" << endl;
	memset(mark, 0, sizeof(mark));
	c = 0;
	for (i = 0; str[i];) {
		if (mark[str[i]-'a'] == 0 && c < k) {
			c++;
			mark[str[i]-'a'] = 1;
			while (mark[str[i]-'a'] == 1) {
				putchar(str[i]);
				i++;
			}
			if (c == k) {
				while (str[i]) {
					putchar(str[i]);
					i++;
				}
			}
			puts("");
		}
	}

	return 0;
}
