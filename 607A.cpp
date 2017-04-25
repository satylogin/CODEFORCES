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

int a[2000001], b[2000001];
int ans[2000001];

int main()
{
	int n, i, j, k, x, y, z, start, mid, end;
	sci(n);
	for (i = 1; i <= n; ++i) {
		sci(a[i]); sci(x);
		b[a[i]] = x;
	}

	sort(a+1, a+n+1);
	ans[1] = 1;
	j = 1;
	for (i = 2; i <= n; ++i) {
		x = a[i] - b[a[i]];
		x = lower_bound(a+1, a+n+1, x) - a;
		x--;
		ans[i] = 1 + ans[x];
		if (ans[i] > ans[j]) j = i;
	}

	cout << n-ans[j] << endl;

	return 0;
}
