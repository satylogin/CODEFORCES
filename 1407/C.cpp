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

int query_and_fill(int x, int y, vector<int> &A) {
	int a, b;
	cout << "? " << x << " " << y << endl;
	cin >> a;
	cout << "? " << y << " " << x << endl;
	cin >> b;
	if (a < b) {
		swap(a, b);
		swap(x, y);
	}
	A[x] = a;

	return y;
}

int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int n, a, b;
	vector<int> A(10005);
	set<int> idx;

	cin >> n;
	for (int i = 1; i <= n; ++i) idx.insert(i);
	while (idx.size() > 1) {
		int a = *idx.begin();
		idx.erase(a);
		int b = *idx.begin();
		idx.erase(b);
		int c = query_and_fill(a, b, A);
		idx.insert(c);
	}
	for (int i = 1; i <= n; ++i) {
		if (A[i] == 0) A[i] = n;
	}
	cout << "! ";
	for (int i = 1; i <= n; ++i) cout << A[i] << " "; cout << endl;


	return 0;
}
