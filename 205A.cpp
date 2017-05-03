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

int arr[1000000];

int main()
{
	int n, i, x, ans, idx;
	cin >> n;
	ans = MOD;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] < ans) ans = arr[i], idx = i+1;
	}
	sort(arr, arr+n);
	if (n > 1 && arr[0] == arr[1]) cout << "Still Rozdil" << endl;
	else cout << idx << endl;

	return 0;
}
