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

multiset <int> se;

int a[200001], b[200001];

int main()
{
	ll n, i, j, k, w, h;

	cin >> n;
	w = 0;
	for (i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		w += a[i];
		se.insert(b[i]);
	}

	for (i = 0; i < n; ++i) {
		se.erase(se.find(b[i]));
		cout << (w-a[i]) * (*(--se.end())) << " ";
		se.insert(b[i]);
	} cout << endl;

	return 0;
}
