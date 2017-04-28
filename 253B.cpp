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

int arr[1000001];
int dp[1000001];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, i, j, k, x, y;
	sci(n);
	for (i = 0; i < n; ++i) {
		sci(arr[i]);
	}
	sort(arr, arr+n);
	j = n-1;
	x = 0;
	for (i = n-1; i >= 0; --i) {
		while (arr[i]+arr[i] < arr[j]) j--;
		dp[i] = j;
		x = max(x, j-i+1);
	}
	cout << n-x << endl;

	return 0;
}
