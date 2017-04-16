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

int arr[10000];
set <int> se;
int mark[100000];

int main()
{
	int n, i, j, k;
	cin >> n;
	for (i = 1; i <= n+n+n; ++i) se.insert(i);
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
		if (se.find(arr[i]) != se.end()) {
			se.erase(arr[i]);
		}
	}
	sort(arr,arr+n);
	ll ans = 0;
	for (i = 0; i < n; ++i) {
		if (mark[arr[i]] == 1) {
			while (*se.begin() < arr[i]) {
				se.erase(se.begin());
			}
			ans += (*se.begin() - arr[i]);
			arr[i] = *se.begin();
			se.erase(se.begin());
		}
		mark[arr[i]] = 1;
	}

	cout << ans << endl;

	return 0;
}
