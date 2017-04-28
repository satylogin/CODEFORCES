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

char str[1000001], tmp[1000001];
int f[1000001], ans[1000001];

void fail(char tmp[], int m)
{
	int i, j, k;
	k = 0;
	f[0] = f[1] = 0;
	for (i = 2; i <= m; ++i) {
		while (k > 0 && tmp[i-1] != tmp[k]) k = f[k];
		if (tmp[i-1] == tmp[k]) k++;
		f[i] = k;
	}
}

void match(char str[], char tmp[], int start, int end)
{
	int i, j, k;
	k = 0;
	for (i = start; i <= end; ++i) {
		while (k > 0 && str[i-1] != tmp[k]) k = f[k];
		if (str[i-1] == tmp[k]) k++;
		ans[i] = k;
	}
}

int main()
{
	int n, m, i, j, k, a, b, c, x, y, z;
	scanf("%s", str);
	n = strlen(str);
	fail(str, n);
	if (f[n] == 0) {
		cout << "Just a legend" << endl;
		return 0;
	}
	for (i = 0; i < f[n]; ++i) tmp[i] = str[i];
	tmp[i] = '\0';

	match(str, tmp, 2, n-1);

	x = f[n];
	while (x != 0) {
		for (i = 2; i < n; ++i) {
			if (f[i] == x) {
				str[x] = '\0';
				printf("%s\n", str);
				return 0;
			}
		}
		x = f[x];
	}
	cout << "Just a legend" << endl;

	return 0;
}
