#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

int main()
{
	int n, m, i, j, k;
	int a[1000], b[1000];
	cin >> n;
	for (i = 0; i < n; ++i) cin >> a[i];
	cin >> m;
	for (i = 0; i < m; ++i) cin >> b[i];
	sort(a, a+n);
	sort(b, b+m);
	i = 0; j = 0;
	k = 0;
	while (i < n && j < m) {
		if (abs(a[i] - b[j]) <= 1) {
			k++; i++; j++;
		} else if (a[i] < b[j]) {
			i++;
		} else {
			j++;
		}
	}
	cout << k << endl;

	return 0;
}
