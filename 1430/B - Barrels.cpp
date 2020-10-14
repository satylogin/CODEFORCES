#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t, n, k;
    vector<long long> A(200005);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> A[i];
        sort(A.begin(), A.begin() + n);
        for (int i = n-2; i >= 0 and k > 0; --i, --k) {
            A[n-1] += A[i];
            A[i] = 0;
        }
        sort(A.begin(), A.begin() + n);
        cout << A[n-1] - A[0] << endl;
    }

    return 0;
}
