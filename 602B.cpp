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

int arr[100001];
multiset <int> se;

int main()
{
	int n, i, j, k;
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	i = 0;
	k = 1;
	se.insert(arr[0]);
	for (j = 1; j < n; ++j) {
		se.insert(arr[j]);
		while ((*(--se.end())-*(se.begin())) > 1) {
			se.erase(se.find(arr[i++]));
		}
		k = max(k, j-i+1);
	}
	cout << k << endl;

	return 0;
}
