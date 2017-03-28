#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[111101], a[100100], b[100100];

int main()
{
	int m, n, i, j, k, c, x, y, z;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	
	m = 0;
	a[1] = 1;
	for (i = 2; i <= n; ++i) {
		if (arr[i] > arr[i-1]) {
			a[i] = a[i-1] + 1;
		} else {
			a[i] = 1;
		}
		m = max(m, a[i]);
	}
	
	b[n] = 1;
	for (i = n-1; i > 0; --i) {
		if (arr[i] < arr[i+1]) {
			b[i] = b[i+1] + 1;
		} else {
			b[i] = 1;
		}	
		m = max(m, b[i]);
	}
	
	m = min(m+1, n);

	for (i = 2; i < n; ++i) {
		if (arr[i+1]-arr[i-1] > 1) {
			m = max(m, a[i-1] + 1 + b[i+1]);
		}
	}

	cout << m << endl;

	return 0;
}
