#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int arr[1000];

int main()
{
	char str[1001];
	int i, j, k, len, x = 9;
	cin >> str;
	for (len = 0; str[len]; ++len) arr[len] = str[len] - '0';
	for (k = len-1; k >= 0; --k) {
		for (j = k-1; j >= 0; --j) {
			for (i = j-1; i >= 0; --i) {
				x = arr[i] * 100 + arr[j] * 10 + arr[k];
				if (x%8 == 0) break;
			}
			if (x%8 == 0) break;
		}
		if (x%8 == 0) break;
	}
	if (x%8 == 0) {
		printf("YES\n%d\n", x);
		return 0;
	}
	for (j = len-1; j >= 0; --j) {
		for (i = j-1; i >= 0; --i) {
			x = arr[i] * 10 + arr[j];
			if (x%8 == 0) break;
		}
		if (x%8 == 0) break;
	}
	if (x%8 == 0) {
		printf("YES\n%d\n", x);
		return 0;
	}
	for (i = len-1; i >= 0; --i) {
		x = arr[i];
		if (x%8 == 0) break;
	}
	if (x%8 == 0) {
		printf("YES\n%d\n", x);
		return 0;
	}
	printf("NO\n");

	return 0;
}
