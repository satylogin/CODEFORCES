#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

bool is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) return false;
	}
	return true;
}

set<int> divisors;
set<int> prime_divisors;
void fill_divisors(int n) {
	divisors.clear();
	prime_divisors.clear();
	for (int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			divisors.insert(i);
			divisors.insert(n / i);
		}
	}
	divisors.erase(1);
	for (int d: divisors) {
		if (is_prime(d)) prime_divisors.insert(d);
	}
}

map<int, int> next_node;

bool process_path(int last_prime, int current_prime) {
	int d = last_prime * current_prime;
	int x = -1;
	for (int y: divisors) {
		if (y % d == 0) {
			x = y;
			break;
		}
	}
	if (x != -1) {
		next_node[last_prime] = x;
		next_node[x] = current_prime;
		divisors.erase(x);
		return true;
	}

	return false;
}

bool fill_nodes_in_path(int x, int y) {
	int last_node = x;
	vector<int> consumed;
	for (int d: divisors) {
		if (d % x == 0) {
			next_node[d] = next_node[last_node];
			next_node[last_node] = d;
			last_node = d;
			consumed.push_back(d);
		}
	}
	for (int c: consumed) divisors.erase(c);
}

bool create_optimal_path(int n) {
	next_node.clear();
	for (int d: prime_divisors) divisors.erase(d);
	int last_prime = *prime_divisors.begin();
	divisors.erase(last_prime);
	set<int>::iterator it = next(prime_divisors.begin());
	while (it != prime_divisors.end()) {
		int p = *it;
		process_path(last_prime, p);
		last_prime = p;
		it = next(it);
	}
	bool optimal_path_exists = process_path(last_prime, *prime_divisors.begin());

	last_prime = *prime_divisors.begin();
	it = next(prime_divisors.begin());
	while (it != prime_divisors.end()) {
		fill_nodes_in_path(last_prime, *it);
		last_prime = *it;
		it = next(it);
	}
	fill_nodes_in_path(last_prime, *prime_divisors.begin());

	return optimal_path_exists;
}

int main()
{
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

	int q, n;
	cin >> q;
	while (q--) {
		cin >> n;
		fill_divisors(n);
		if (prime_divisors.size() == 1) {
			for (auto it: divisors) cout << it << " "; cout << endl;
			cout << 0 << endl;
			continue;
		}
		int len = divisors.size();
		bool optimal_path_exists = create_optimal_path(n);
		int x = *prime_divisors.begin();
		for (int i = 0; i < len; ++i) {
			cout << x << " ";
			x = next_node[x];
		} cout << endl;
		if (optimal_path_exists) cout << 0 << endl;
		else cout << 1 << endl;
	}

	return 0;
}
