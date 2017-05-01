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

int arr[100000];

int main()
{
	int n, i, j, k;
	cin >> n;
	if (n == 1 || n == 2) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}

	if (n == 3) {
		cout << 2 << endl << "1 3" << endl;
		return 0;
	}

	if (n == 4) {
		cout << 4 << "\n3 1 4 2\n";
		return 0;
	}

	k = 1;
	for (i = 1; i <= n; i += 2) {
		arr[i] = k++;
	}
	for (i = 2; i <= n; i += 2) {
		arr[i] = k++;
	}
	cout << n << endl;
	for (i = 1; i <= n; ++i) cout << arr[i] << " "; cout << endl;

	return 0;
}
