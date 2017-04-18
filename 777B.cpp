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

string s1, s2;

int main()
{
	int n, i, j, k, a, b, c;
	cin >> n;
	cin >> s1 >> s2;
	a = b = 0;	
	
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	j = 0;
	for (i = 0; i < n; ++i) {
		while (j < n && s2[j] < s1[i]) j++;
		if (j < n && s2[j] >= s1[i]) a++, j++;
	}
	a = n-a;

	j = 0;
	for (i = 0; i < n; ++i) {
		while (j < n && s2[j] <= s1[i]) j++;
		if (j < n && s2[j] > s1[i]) b++, j++;
	}

	cout << a << endl << b << endl;


	return 0;
}
