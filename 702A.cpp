#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int ans[100001], arr[100001];

int main()
{
	int n, i, j, k;
	cin >> n;
	arr[0] = MOD;
	k = 0;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
		if (arr[i] > arr[i-1]) ans[i] = 1 + ans[i-1];
		else ans[i] = 1;
		k = max(k, ans[i]);
	}
	cout << k << endl;

	return 0;
}
