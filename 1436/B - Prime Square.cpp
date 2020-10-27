#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t, n, i, j;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<vector<int>> A(n, vector<int>(n, 0));
        for (i = 0; i < n; ++i) {
            for (j = i; j < i+2; ++j) {
                A[i][(j+1) % n] = 1;
            }
        }
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
