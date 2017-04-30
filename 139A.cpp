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

int arr[8];

int main()
{
	int n, i, j, k;
	cin >> n;
	for (i = 1; i <= 7; ++i) cin >> arr[i];
	i = 1;
	while (n) {
		n = max(0, n-arr[i]);
		if (n == 0) break;
		i++;
		if (i > 7) i = 1;
	}
	cout << i << endl;

	return 0;
}
