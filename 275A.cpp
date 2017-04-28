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

int arr[6][6], ans[6][6];

int main()
{
	int i, j, k;
	for (i = 1; i <= 3; ++i) {
		for (j = 1; j <= 3; ++j) {
			cin >> arr[i][j];
		}	
	}

	for (i = 1; i <= 3; ++i) {
		for (j = 1; j <= 3; ++j) {
			k = 0;
			k += arr[i][j];
			k += arr[i-1][j];
			k += arr[i+1][j];
			k += arr[i][j+1];
			k += arr[i][j-1];
			k &= 1;
			ans[i][j] = 1 ^ k;
		}
	}

	for (i = 1; i <= 3; ++i) {
		for (j = 1; j <= 3; ++j) {
			cout << ans[i][j];
		} cout << endl;
	}

	return 0;
}
