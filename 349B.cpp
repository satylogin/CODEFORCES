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

int ans[1000001];
int cost[10];
stack <int> st;

int main()
{
	int x, i, j, k, a, b, c, len, d;
	cin >> c;
	a = MOD;
	for (i = 1; i <= 9; ++i) {
		cin >> cost[i];
		if (cost[i] <= a) a = cost[i], d = i;
	}

	if (c < a) {cout << -1 << endl; return 0;}

	len = c / a;
	for (i = 0; i < len; ++i) {
		ans[i] = d;
	}

	if (d != 9) {
		x = len * a;
		i = 0;
		while (i < len) {
			for (j = 9; j > d; --j) {
				if (x-cost[ans[i]]+cost[j] <= c) {
					x = x - cost[ans[i]] + cost[j];
					ans[i] = j;
					break;
				}
			}
			i++;
		}
	}

	for (i = 0; i < len; ++i) {
		printf("%d", ans[i]);
	} 
	cout << endl;

	return 0;
}
