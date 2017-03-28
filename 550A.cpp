#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define scan(x) scanf("%d", &x)

vector <int> v1, v2;

int main()
{
	int i, j, k;
	string str;
	cin >> str;

	k = 0;
	for (i = 0; str[i]; ++i) {
		if (str[i] == 'A' && str[i+1] == 'B') {
			v1.pb(i);
		} else if (str[i] == 'B' && str[i+1] == 'A') {
			v2.pb(i);
		}
	}
	if (v1.size() && v2.size() && (abs(v1[0] - v2[v2.size()-1]) > 1 || abs(v2[0] - v1[v1.size()-1]) > 1)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
