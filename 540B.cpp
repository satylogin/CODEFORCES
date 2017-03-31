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
	int c, n, k, p, x, y, i, j, a, b;
	cin >> n >> k >> p >> x >> y;
	for (i = 0; i < k; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+k);
	for (i = 0; i < k; ++i) {
		if (arr[i] >= y) break;
	}
	a = (k - i - 1);

	if (a < n/2) {
		i = k;
		while (a != n/2 && i <= n) {
			arr[i++] = y;
			a++;
		}
		if (i > n) {
			cout << -1 << endl; return 0;
		}
		for (; i < n; ++i) {
			arr[i] = 1;
		}
	} else {
		for (i = k; i < n; ++i) {
			arr[i] = 1;
		}
	}

	c = 0;
	for (i = 0; i < n; ++i) {
		c += arr[i];
	}
	if (c > x) cout << -1 << endl;	
	else {
		for (i = k; i < n; ++i) {
			cout << arr[i] << " ";
		} cout << endl;
	}

	return 0;
}
