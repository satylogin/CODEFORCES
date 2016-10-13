#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair

int mark[100001];
int arr[100001];

int main()
{
	int n, k, i, j, a, b, x, y;
	x = y = -1;
	cin >> n >> k;
	a = b = 1;
	j = 0;
	for (i = 1; i <= n; ++i, ++b) {
		scanf("%d", &arr[i]);
		if (mark[arr[i]] == 0) j++;
		mark[arr[i]]++;
		if (j == k) {
			while (j == k) {
				if (x == -1 || (b-a < y-x)) {
					x = a; y = b;
				}
				if (mark[arr[a]] == 1) j--;
				mark[arr[a]]--;
				a++;
			}
			break;
		}
	}
	cout << x << " " << y << endl;

	return 0;
}
