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
#define PI 3.14159265

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		map<int, int> freq;
		int x;
		while (n--) {
			cin >> x;
			freq[x]++;
		}
		int ans = 0, i = 0;
		while (freq[i] >= 2) i++;
		ans += i;
		while (freq[i] >= 1) i++;
		ans += i;
		cout << ans << endl;
	}

	return 0;
}
