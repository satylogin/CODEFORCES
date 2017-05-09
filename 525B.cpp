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

char str[1000000];
ll arr[1000000];

int main()
{
	ll i, j, k, n, m;
	scanf("%s", str);
	n = strlen(str);
	cin >> m;
	while (m--) {
		scl(k);
		arr[k]++;
		arr[n-k+2]--;
	}
	for (i = 1; i <= n; ++i) {
		arr[i] += arr[i-1];
	}
	for (i = 1; i <= n; ++i) {
		arr[i] &= 1;
	}
	for (i = 1; i <= n/2; ++i) {
		if (arr[i]) swap(str[i-1], str[n-i]);
	}
	printf("%s\n", str);

	return 0;
}
