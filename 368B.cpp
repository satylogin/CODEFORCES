#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int mark[100001], arr[100001], ans[100001];

int main()
{
	int n, m, q, i, j, k;
	cin >> n >> m;
	
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	for (i = n; i > 0; --i) {
		if (mark[arr[i]] == 0) {
			ans[i] = 1 + ans[i+1];
		} else {
			ans[i] = ans[i+1];
		}
		mark[arr[i]] = 1;
	}

	while (m--) {
		cin >> i;
		cout << ans[i] << endl;
	}	

	return 0;
}
