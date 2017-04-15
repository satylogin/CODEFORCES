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

ll arr[100001];

int main()
{
	ll n, i, j, k;
	ll s = 0;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	k = 0;
	for (i = 0; i < n; ++i) {
		if (s <= arr[i]) {
			k++;
			s += arr[i];
		}
	}
	cout << k << endl;

	return 0;
}
