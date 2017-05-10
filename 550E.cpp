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

int arr[1000000];

int main()
{
	int n, i, j, k, x, y, z;
	sci(n);
	for (i = 0; i < n; ++i) {
		sci(arr[i]);
	}

	if (n == 1) {
		if (arr[0] == 0) cout << "YES\n0" << endl;
		else cout << "NO" << endl;
		return 0;
	}

	if (n == 2) {
		if (arr[0] == 1 && arr[1] == 0) cout << "YES\n1->0" << endl;
		else cout << "NO" << endl;
		return 0;
	}

	if (arr[n-1] == 1) {
		cout << "NO" << endl;
		return 0;
	}

	if (arr[n-2] == 0) {
		i = n-3;
		while (i >= 0 && arr[i] == 1) i--;
		if (i < 0) {
			cout << "NO" << endl;
			return 0;
		}
		cout << "YES" << endl;
		for (j = 0; j < i; ++j) {
			if (j) printf("->");
			printf("%d", arr[j]);
		}	
		if (j) cout << "->(0->(";
		else cout << "(0->(";
		for (j = i+1; j < n-1; ++j) {
			if (j != n-2) printf("%d->", arr[j]);
			else printf("%d", arr[j]);
		}
		cout << "))->0" << endl;
	} else {
		cout << "YES" << endl;
		for (i = 0; i < n; ++i) {
			if (i) printf("->");
			printf("%d", arr[i]);
		}
		cout << endl;
		return 0;
	}

	return 0;
}
