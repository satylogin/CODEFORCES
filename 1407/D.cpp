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
#define eps 1e-9
#define PI 3.14159265

const int N = 300005;
vector<int> A(N), ans(N, MOD);
vector<int> left_lower_bound(N);
vector<int> left_upper_bound(N);
vector<int> right_lower_bound(N);
vector<int> right_upper_bound(N);

bool compare(int x, int y, string cmp) {
	if (cmp == "less") return x < y;
	else if (cmp == "great") return x > y;
}

void find(int start, int end, int inc, int init, string cmp, vector<int> &v) {
	stack<int> boundary;
	A[start - inc] = init;
	boundary.push(start - inc);
	for (int i = start; i != end; i += inc) {
		while (compare(A[boundary.top()], A[i], cmp)) boundary.pop();
		v[i] = boundary.top();
		boundary.push(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> A[i];
	find(1, n+1, 1, INT_MAX, "less", left_upper_bound);
	find(n, 0, -1, INT_MAX, "less", right_upper_bound);
	find(1, n+1, 1, INT_MIN, "great", left_lower_bound);
	find(n, 0, -1, INT_MIN, "great", right_lower_bound);
	ans[1] = 0;
	for (int i = 1; i <= n; ++i) {
		ans[i] = min(ans[i], ans[left_lower_bound[i]] + 1);
		ans[i] = min(ans[i], ans[left_upper_bound[i]] + 1);
		ans[right_lower_bound[i]] = min(ans[right_lower_bound[i]], ans[i] + 1);
		ans[right_upper_bound[i]] = min(ans[right_upper_bound[i]], ans[i] + 1);
	} 
	cout << ans[n] << endl;

	return 0;
}
