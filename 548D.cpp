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

int l[200001], r[200001];
int ans[200001], arr[200001];
stack <int> s1, s2;

int main()
{
	int n, m, i, j, k, a, b, c, x, y, z;
	cin >> n;
	for (i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for (i = 1, j = n; i <= n && j > 0; ++i, --j) {
		if (s1.empty() || arr[i] >= arr[s1.top()]) {
			s1.push(i);
		} else {
			while (!s1.empty() && arr[i] < arr[s1.top()]) {
				r[s1.top()] = i;
				s1.pop();
			}
			s1.push(i);
		}
		if (s2.empty() || arr[j] >= arr[s2.top()]) {
			s2.push(j);
		} else {
			while (!s2.empty() && arr[j] < arr[s2.top()]) {
				l[s2.top()] = j;
				s2.pop();
			}
			s2.push(j);
		}
	}
	while (!s1.empty()) {
		r[s1.top()] = n+1;
		s1.pop();
	}
	while (!s2.empty()) {
		l[s2.top()] = 0;
		s2.pop();
	}
	for (i = 1; i <= n; ++i) {
		x = arr[i];
		y = r[i]-l[i]-1;
		ans[y] = max(ans[y], x);
	}
	for (i = n; i > 0; --i) {
		ans[i] = max(ans[i], ans[i+1]);
	}
	for (i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;

	return 0;
}
