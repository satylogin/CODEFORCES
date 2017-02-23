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
	int i, k, arr[13], s = 0;
	cin >> k;
	for (i = 0; i < 12; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr+12);
	arr[12] = 0;
	for (i = 12; i >= 0; --i) {
		s += arr[i];
		if (s >= k) {
			break;
		}
	}

	if (s >= k) {
		cout << 12 - i << endl;
	} else {
		cout << -1 << endl;
	}

	return 0;
}
