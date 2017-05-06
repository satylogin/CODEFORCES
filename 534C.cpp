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

ll arr[200001];

int main()
{
	ll n, x, i, j, k, a, b, c;
	cin >> n >> x;

	k = 0;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
		k += arr[i];
	}

	for (i = 0; i < n; ++i) {
		a = max(1ll, x - k + arr[i]);
		b = min(arr[i], x-n+1);
		c = arr[i] - (b-a+1);
		cout << c << " ";
	} cout << endl;

	return 0;
}
