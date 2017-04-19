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

char str[1000];
int a, b, c;

int main()
{
	int n, i, j, k;
	cin >> n >> str;
	for (i = 0; str[i]; ++i) {
		if (str[i] == 'R') a++;
		else if (str[i] == 'G') b++;
		else c++;
	}

	if (a != 0 && b != 0 && c != 0) {
		cout << "BGR" << endl; 
		return 0;
	}
	k = 0;
	if (a) k++; 
	if (b) k++; 
	if (c) k++;
	if (k == 2 && a == 0) {
		if (b == 1 && c == 1) {
			cout << "R" << endl;
			return 0;
		} else if (b == 1) {
			cout << "GR" << endl;
			return 0;
		} else if (c == 1) {
			cout << "BR" << endl;
			return 0;
		} else {
			cout << "BGR" << endl;
			return 0;
		}
	}
	if (k == 2 && b == 0) {
		if (a == 1 && c == 1) {
			cout << "G" << endl;
			return 0;
		} else if (a == 1) {
			cout << "GR" << endl;
			return 0;
		} else if (c == 1) {
			cout << "BG" << endl;
			return 0;
		} else {
			cout << "BGR" << endl;
			return 0;
		}
	}
	if (k == 2 && c == 0) {
		if (b == 1 && a == 1) {
			cout << "B" << endl;
			return 0;
		} else if (b == 1) {
			cout << "BG" << endl;
			return 0;
		} else if (a == 1) {
			cout << "BR" << endl;
			return 0;
		} else {
			cout << "BGR" << endl;
			return 0;
		}
	}
	if (a != 0) cout << "R" << endl;
	else if (b != 0) cout << "G" << endl;
	else cout << "B" << endl;

	return 0;
}
