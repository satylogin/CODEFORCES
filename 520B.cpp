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

int dp[10001], vis[10001], req;

int get(int x)
{
	queue <int> q;
	q.push(x);
	vis[x] = 1;
	int ans = 0, z;
	while (!q.empty()) {
		z = q.size();
		while (z--) {
			x = q.front();
			q.pop();
			if (x > 1 && !vis[x-1]) {
				vis[x-1] = 1;
				dp[x-1] = 1 + dp[x];
				q.push(x-1);
			}
			if (2*x > 0 && 2*x <= 10000 && !vis[2*x]) {
				vis[2*x] = 1;
				dp[2*x] = 1 + dp[x];
				q.push(2*x);
			}
		}
	}
	return dp[req];
}

int main()
{
	int n;
	cin >> n >> req;
	cout << get(n) << endl;

	return 0;
}
