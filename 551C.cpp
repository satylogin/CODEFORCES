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
#define fi first
#define sc second

int arr[100001], tmp[100001];

int main()
{
	ll n, m, i, j, k, a, b, c, x, y, z;
	ll start, mid, end;

	cin >> n >> m;
	for (i = 0; i < n; ++i) {
		cin >> tmp[i];
		if (tmp[i]) x = i;
	}

	start = x+2;
	end = 1e18;
	z = -1;
	while (start <= end) {
		for (i = 0; i < n; ++i) arr[i] = tmp[i];

		mid = start + (end - start) / 2;
		x = 0;
		y = mid;

		for (i = n-1; i >= 0;) {
			if (arr[i] == 0) {
				i--;
				continue;
			}
			if (arr[i] <= mid-y) {
				y += arr[i];
				i--;
			} else {
				x++;
				arr[i] -= (mid-y);
				y = i+1;
			}
		}

		if (x <= m) {
			z = mid;
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}

	cout << z << endl;

	return 0;
}
