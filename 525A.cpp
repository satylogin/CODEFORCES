#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[26], ans;
char str[1000000];

int main()
{
	int n, i, j, k;
	cin >> n >> str;
	for (i = 0; str[i] != '\0'; ++i) {
		arr[str[i]-'a']++;
		i++;
		if (arr[str[i]-'A'] > 0) arr[str[i]-'A']--;
		else ans++;
	}
	cout << ans << endl;

	return 0;
}
