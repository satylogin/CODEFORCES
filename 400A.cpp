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

vector <int> v[6];
queue <string> st;

void init()
{
	int k = 0;
	for (int i = 1; i <= 12; ++i) {
		if (12%i) continue;
		int j = 12 / i;
		for (int y = 0; y < j; ++y) {
			int a = 0;
			for (int x = 0; x < i; ++x) {
				a |= (1<<(y + x*j));
			}
			v[k].pb(a);	
		}
		k++;
	}
}

int main()
{
	init();
	string str;
	int t, i, j, k, a, b;
	sci(t);
	while (t--) {
		cin >> str;
		a = 0;
		for (i = 0; str[i]; ++i) {
			if (str[i] == 'X') a |= (1<<i);
		}
		b = 0;
		for (i = 0; i < 6; ++i) {
			for (j = 0; j < v[i].size(); ++j) {
				if ((a&v[i][j]) == v[i][j]) {
					b++;
					if (i == 0) st.push("1x12");
					if (i == 1) st.push("2x6");
					if (i == 2) st.push("3x4");
					if (i == 3) st.push("4x3");
					if (i == 4) st.push("6x2");
					if (i == 5) st.push("12x1");
					break;
				}
			}
		}
		cout << b << " ";
		while (!st.empty()) {
			cout << st.front() <<  " "; st.pop();
		} cout << endl;
	}

	return 0;
}
