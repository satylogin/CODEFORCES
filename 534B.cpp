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

int arr[1000];

int main()
{
	int v1, v2, i, j, k, t, d;
	cin >> v1 >> v2 >> t >> d;

	arr[0] = v1;
	arr[t-1] = v2;
	for (i = t-2; i > 0; --i) {
		arr[i] = arr[i+1] + d;
	}

	for (i = 1; i < t-1; ++i) {
		arr[i] = min(arr[i], arr[i-1]+d);
	}

	ll c = 0;
	for (i = 0; i < t; ++i) {
		c += arr[i];
		//cout << arr[i] << " ";
	}
	//cout << endl;
	cout << c << endl;

	return 0;
}
