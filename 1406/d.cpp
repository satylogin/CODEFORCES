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

const int N = 100005;
vector<long long> A(N, 0);

long long get_sum(int n) {
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans += max(0ll, A[i]);
	}

	return ans;
}

long long get_ans(long long _sum) {
	return ceil((long double)(A[1] + _sum) / 2.0);	
}

long long update(int x, int v, long long _sum) {
	if (A[x] > 0) _sum -= A[x];
	A[x] += v;
	if (A[x] > 0) _sum += A[x];

	return _sum;
}

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int n, q, i, l, r, x;
	cin >> n;
	for (i = 1; i <= n; ++i) cin >> A[i];
	for (i = n; i >= 1; --i) A[i] -= A[i-1];
	long long _sum = get_sum(n);
	cout << get_ans(_sum) << endl;
	cin >> q;
	while (q--) {
		cin >> l >> r >> x;
		if (l == 1) A[1] += x;
		else _sum = update(l, x, _sum);
		if (r+1 <= n) _sum = update(r+1, -x, _sum);
		cout << get_ans(_sum) << endl;
	}
 
	return 0;
}
