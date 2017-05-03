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

int main()
{
	int n, i, j, k, x, a, b, arr[1000];
	x = MOD;
	cin >> n;
	for (i = 0; i < n;  ++i) {
		cin >> arr[i];
	}	
	for (i = 0; i < n-1; ++i) {
		if (abs(arr[i]-arr[i+1]) < x) {
			x = abs(arr[i]-arr[i+1]);
			a = i;
			b = i+1;
		}
	}
	if (abs(arr[0]-arr[n-1]) < x) {
		a = 0; b = n-1;
	}
	a++; b++;
	cout << a << " " << b << endl;

	return 0;
}
