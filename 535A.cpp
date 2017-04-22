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

string str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", 
		"twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

string str1[] = {"zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

void print(int x)
{
	if (x <= 20) {
		cout << str[x] << endl;
	} else {
		int a = x / 10;
		int b = x % 10;
		if (b != 0) cout << str1[a] << "-" << str[b] << endl;
		else cout << str1[a] << endl;
	}
}	

int main()
{
	int x;
	cin >> x;
	print(x);

	return 0;
}
