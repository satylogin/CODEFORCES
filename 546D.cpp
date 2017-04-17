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

vector <int> p;
int pr[5000001];
ll ans[5000001], k, tmp[5000001];

void sieve()
{
	for (int i = 2; i*i <= 5000000; ++i) {
		if (pr[i] == 0) {
			for (int j = i+i; j <= 5000000; j += i) {
				if (!pr[j]) pr[j] = i;
			}
		}
	}

}

int main()
{
	sieve();
	ll t, n, m, i, j, a, b, c, x, y, z, A, B;
	j = 0;
	for (i = 2; i <= 5000000; ++i) {
		x = pr[i];
		if (x == 0) x = i;
		tmp[i] = 1 + tmp[i/x];
		ans[i] = ans[i-1] + tmp[i];
	}
	
	scl(t);
	while (t--) {
		scl(a); scl(b);
		printf("%lld\n", ans[a]-ans[b]);
	}

	return 0;
}
