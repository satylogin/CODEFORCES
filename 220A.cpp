#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[100001], sor[100001];

int main()
{
	int i, n, cnt = 0;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
		sor[i] = arr[i];
	}
	sort(sor, sor+n);
	for (i = 0; i < n; ++i) {
		if (arr[i] != sor[i]) cnt++;
	}
	if (cnt <= 2) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
