#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	vector<long long> T(100);
	long long lim = 1e18;
	for (long long i = 1; i <= 31; ++i) {
		long long m = (1ll<<(i-1));
		T[i] = m * m + 2 * T[i-1];
	}

	long long q, x;
	cin >> q;
	while (q--) {
		cin >> x;
		long long ans = 0;
		for (long long i = 1; i <= 31; ++i) {
			if (T[i] <= x) {
				x -= T[i];
				ans++;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
