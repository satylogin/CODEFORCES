#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int arr[1000];

int main()
{
	int n, k, i, j, a, cnt;
	cin >> n >> k;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	cnt = 0;
	for (i = 1; i < n; ++i) {
		j = arr[i-1];
		a = max(0, k-j-arr[i]);
		cnt += a;
		arr[i] += a;
	}
	cout << cnt << endl;
	for (i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	} cout << endl;

	return 0;
}
