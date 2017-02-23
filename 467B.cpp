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
	int n, m, k, i, j, a, b, c;

	cin >> n >> m >> k;
	for (i = 0; i <= m; ++i) {
		cin >> arr[i];
	}
	a = arr[m];
	c = 0;
	for (i = 0; i < m; ++i) {
		b = a ^ arr[i];
		b = __builtin_popcount(b);
		if (b <= k) c++;
	}
	cout << c << endl;

	return 0;
}
