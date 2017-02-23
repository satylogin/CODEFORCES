#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[100001];

int main()
{
	int n, i, a, b;
	cin >> n;
	
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (i = 1; i <= n; ++i) {
		if (i == 1) {
			cout << arr[2] - arr[1] << " ";
			cout << arr[n] - arr[1] << endl;
		} else if (i == n) {
			cout << arr[n] - arr[n-1] << " ";
			cout << arr[n] - arr[1] << endl;
		} else {
			a = min(arr[i+1] - arr[i], arr[i] - arr[i-1]);
			b = max(arr[i] - arr[1], arr[n] - arr[i]);
			cout << a << " " << b << endl;
		}
	}

	return 0;
}
