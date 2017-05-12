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

int m[26][26];
int m1[26], m2[26];

char str1[1000000], str2[1000000];

int main()
{
	int n, i, j, k;
	cin >> n;
	scanf("%s %s", &str1[1], &str2[1]);

	k = 0;
	for (i = 1; i <= n; ++i) {
		if (str1[i] != str2[i]) {
			k++;
			m1[str1[i]-'a'] = i;
			m2[str2[i]-'a'] = i;
			m[str1[i]-'a'][str2[i]-'a'] = i;
		}
	}

	int a = -1, b = -1;


	for (i = 0; i < 26; ++i) {
		for (j = 0; j < 26; ++j) {
			if ((m[i][j] != 0)  && (m[j][i] != 0)) {
				k -= 2;
				a = m[i][j];
				b = m[j][i];
				break;
			}
		}
		if (a != -1) break;
	}

	if (a == -1) {
		for (i = 0; i < 26; ++i) {
			if (m1[i]!=0 && m2[i]!=0) {
				k -= 1;
				a = m1[i];
				b = m2[i];
				break;
			}
		}
	}

	cout << k << endl << a << " " << b << endl;

	return 0;
}
