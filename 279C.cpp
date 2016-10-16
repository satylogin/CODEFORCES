#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[1000000], rt[1000000], lt[1000000];

int main()
{
	int n, m, i, j, k, a, b, c, x, y, z;
	cin >> n >> m;
	for (i = 1; i <= n; ++i) {
		scanf("%d", &arr[i]);
	}
	lt[1] = 1;
	for (i = 2; i <= n; ++i) {
		if (arr[i] <= arr[i-1]) lt[i] = lt[i-1];
		else lt[i] = i;
	}
	rt[n] = n;
	for (i = n-1; i > 0; --i) {
		if (arr[i] <= arr[i+1]) rt[i] = rt[i+1];
		else rt[i] = i;
	}
	//for (i = 1; i <= n; ++i) cout << rt[i] << " "; cout << endl;
	//for (i = 1; i <= n; ++i) cout << lt[i] << " "; cout << endl;
	while (m--) {
		scanf("%d %d", &x, &y);
		if (rt[x] >= lt[y]) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
