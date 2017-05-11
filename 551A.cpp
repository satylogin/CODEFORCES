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

pii arr[100000];
int ans[100001];

int main()
{
	int n, i, j, k, x, y;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i].fi;
		arr[i].sc = i;
	}
	sort(arr+1, arr+n+1);
	
	for (i = n; i > 0; --i) {
		if (arr[i].fi == arr[i+1].fi) {
			ans[arr[i].sc] = ans[arr[i+1].sc];
		} else {
			ans[arr[i].sc] = n-i+1;
		}
	}

	for (i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}
