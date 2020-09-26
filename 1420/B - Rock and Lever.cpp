#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define EPS 1e-9
#define PI 3.14159265

int extract(int x) {
	for (int i = 30; i >= 0; --i) {
		if (x&(1<<i)) return i;
	}
	return -1;
}

long long count(int n, vector<int> &A) {
	map<int, int> freq;
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += freq[extract(A[i])];
		freq[extract(A[i])]++;
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int t, n, i;
	vector<int> A(100000);
	cin >> t;
	while (t--) {
		cin >> n;
		for (i = 0; i < n; ++i) cin >> A[i];
		cout << count(n, A) << endl;
	}

	return 0;
}
