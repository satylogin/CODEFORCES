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
	int n, a, b, lit, sli, sal;
	cin >> n;
	cin >> a >> b;
	lit = a*b;
	cin >> a >> b;
	sli = a*b;
	cin >> sal;
	cin >> a >> b;
	a = min(lit/a, min(sli, sal/b));
	cout << a/n << endl;

	return 0;
}
