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

class Garbage {
public:
	map<int, int> pile_end;
	map<int, int> pile_start;
	multiset<int> gap;
	int size;

	Garbage() {
		size = 0;
		gap.insert(0);
	}

	void insert(int x) {
		map<int, int>::iterator it;
		int l = -1, r = -1;
		if ((it = pile_start.upper_bound(x)) != pile_start.end()) {
			r = it->fi;
		}
		if (it != pile_start.begin()) {
			--it;
			l = it->fi;
		}
		pile_start[x] = l;
		pile_end[x] = r;
		if (l != -1) {
			gap.insert(x - l);
			pile_end[l] = x;
		}
		if (r != -1) {
			gap.insert(r - x);
			pile_start[r] = x;
		}
		if (l != -1 and r != -1) gap.erase(gap.find(r-l));
		size += 1;
	}

	void erase(int x) {
		if (pile_end[x] != -1) {
			gap.erase(gap.find(pile_end[x] - x));
			pile_start[pile_end[x]] = pile_start[x];
		}
		if (pile_start[x] != -1) {
			gap.erase(gap.find(x - pile_start[x]));
			pile_end[pile_start[x]] = pile_end[x];
		}
		if (pile_start[x] != -1 and pile_end[x] != -1) {
			gap.insert(pile_end[x] - pile_start[x]);
		}
		pile_start.erase(x);
		pile_end.erase(x);
		size -= 1;
	}

	int min_moves_to_clean() {
		return (size > 2 ? pile_end.rbegin()->fi - pile_start.begin()->fi - *gap.rbegin() : 0);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int n, q, t, x;
	Garbage garbage;

	cin >> n >> q;
	while (n--) {
		cin >> x;
		garbage.insert(x);
	}
	cout << garbage.min_moves_to_clean() << endl;
	while (q--) {
		cin >> t >> x;
		if (t == 0) garbage.erase(x);
		else garbage.insert(x);
		cout << garbage.min_moves_to_clean() << endl;
	}
 
	return 0;
}
