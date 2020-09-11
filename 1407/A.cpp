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
#define eps 1e-9

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int t, n, i, x;
	vector<int> v(1000);

	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) cin >> v[i];
		map<int, int> freq;
		for (i = 0; i < n; ++i) freq[v[i]]++;
		if (freq[0] >= n/2) {
			cout << n/2 << endl;
			for (i = 0; i < n/2; ++i) cout << 0 << " "; cout << endl;
		} else {
			n = min(n/2 + (n/2)%2, freq[1]);
			cout << n << endl;
			for (i = 0; i < n; ++i) cout << 1 << " "; cout << endl;
		}
	}
 
	return 0;
}
