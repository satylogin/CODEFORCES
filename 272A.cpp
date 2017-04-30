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

int arr[1000];

int main()
{
	int n, i, j, k;
	cin >> n;
	k = 0;
	for (i = 0; i < n; ++i) {
		cin >> j, k += j;
	}

	n++;
	k %= n;
	j = 0;
	if ((k+1)%n != 1) j++;
	if ((k+2)%n != 1) j++;
	if ((k+3)%n != 1) j++;
	if ((k+4)%n != 1) j++;
	if ((k+5)%n != 1) j++;
	cout << j << endl;


	return 0;
}
