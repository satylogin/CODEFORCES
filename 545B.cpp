#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

char str1[1000000], str2[1000000], str3[1000000];

int main()
{
	scanf("%s %s", str1, str2);
	int i, j, k, a, b, c;
	a = b = -1;
	for (i = 0; str1[i] != '\0'; ++i) {
		if (str1[i] != str2[i]) {
			if (a == -1) a = i;
			else {
				str3[a] = str1[a];
				str3[i] = str2[i];
				a = -1;
			}
		} else {
			str3[i] = str1[i];
		}
	}
	str3[i] = '\0';
	if (a == -1) {
		printf("%s\n", str3);
	} else {
		printf("impossible\n");
	}

	return 0;
}
