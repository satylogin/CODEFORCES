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

pii arr[200001];

int main()
{
	int n, i, j, k, x, y, ans;
	
	sci(n);
	for (i = 0; i < n; ++i) {
		sci(x); sci(y);
		arr[i] = mkp(x+y, x-y);
	}
	
	sort(arr, arr+n);
	
	ans = 0;
	x = INT_MIN;
	for (i = 0; i < n; ++i) {
		if (arr[i].sc >= x) x = arr[i].fi, ++ans;
	}

	cout << ans << endl;
	
	return 0;
}
