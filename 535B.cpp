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

vector <ll> v;

void make(ll x)
{
	if (x > MOD) return;
	v.pb(x);
	make(x*10 + 4);
	make(x*10 + 7);
}

int main()
{
	make(0);
	sort(v.begin(), v.end());
	ll n;
	cin >> n;
	cout << (lower_bound(v.begin(), v.end(), n) - v.begin()) << endl;

	return 0;
}
