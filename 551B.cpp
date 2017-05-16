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

int n, m, k, ma[30], mb[30], ms[30];
char s[100001], a[100001], b[100001], ans[100001];
int ls, la, lb;

int main()
{
	int i, j, x, y, z;
	scanf("%s %s %s", s, a, b);

	n = strlen(s);
	m = strlen(a);
	k = strlen(b);
	
	for (i = 0; i < n; ++i) ms[s[i]-'a']++;
	for (i = 0; i < m; ++i) ma[a[i]-'a']++;
	for (i = 0; i < k; ++i) mb[b[i]-'a']++;

	int ans_ = 0;
	for (i = 0; ; ++i) {
		x = n;
		for (j = 0; j < 26; ++j) {
			if (ma[j]) x = min(x, ms[j] / ma[j]);
		}
		if (x+i >= ans_) {
			ans_ = x+i;
			la = x;
			lb = i;
		}
		y = 1;
		for (j = 0; j < 26; ++j) {
			ms[j] -= mb[j];
			if (ms[j] < 0) y = 0;
		}
		if (!y) break;
	}

	z = 0;
	memset(ms, 0, sizeof(ms));
	for (i = 0; i < n; ++i) ms[s[i]-'a']++;
	for (i = 0; i < la; ++i) {
		for (j = 0; j < m; ++j) {
			ans[z++] = a[j];
			ms[a[j]-'a']--;
		}
	}
	for (i = 0; i < lb; ++i) {
		for (j = 0; j < k; ++j) {
			ans[z++] = b[j];
			ms[b[j]-'a']--;
		}
	}
	for (i = 0; i < 26; ++i) {
		while (ms[i] > 0) {
			ms[i]--;
			ans[z++] = i + 'a';
		}
	}
	ans[z] = '\0';
	printf("%s\n", ans);

	return 0;
}
