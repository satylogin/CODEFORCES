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

char str[1000001], tmp[1000001];
int arr[1000001], z[1000001];

void fail(int m)
{
	int i, j, k, l, r;
	l = r = 0;
	for (i = 1; i < m; ++i) {
		if (i > r) {
			l = r = i;
			while (r < m && tmp[r-l] == tmp[r]) r++;
			z[i] = r-l; r--;
		} else {
			k = i-l;
			if (z[k] < r-i+1) z[i] = z[k];
			else {
				l = i;
				while (r < m && tmp[r-l] == tmp[r]) r++;
				z[i] = r-l; r--;
			}
		}	
	}
}

int main()
{
	int n, m, i, j, k, a, b, c, x, y;
	cin >> n >> m;
	scanf("%s", tmp);

	int len = strlen(tmp);
	for (i = 1; i <= m; ++i) sci(arr[i]);
	arr[0] = -MOD;
	sort(arr, arr+m+1);
	fail(len);

	for (i = 0; i < n; ++i) str[i] = '?';

	for (i = 1; i <= m; ++i) {
		if (arr[i]-arr[i-1] >= len) {
			for (j = arr[i]-1, k = 0; k < len; ++j, ++k) {
				str[j] = tmp[k];
			}
		} else {
			b = arr[i] - arr[i-1];
			a = len - b;
			if (z[b] == a) {
				for (j = arr[i-1]+len-1, k = a; k < len; ++j, ++k) {
					str[j] = tmp[k];
				}
			} else {
				cout << 0 << endl;
				return 0;
			}
		}
	}

	ll ans = 1;
	//for (i = 0; i < n; ++i) cout << str[i]; cout << endl;
	for (i = 0; i < n; ++i) {
		if (str[i] == '?') ans = (ans * 26) % MOD;
	}

	cout << ans << endl;

	return 0;
}
