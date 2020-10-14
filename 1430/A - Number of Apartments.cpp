#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long a = 0, b = 0, c = 0;
        a = n / 3;
        if (n % 3 == 0) {
            cout << a << " 0 0" << endl;
        } else if (n % 3 == 1) {
            if (a >= 2) cout << a-2 << " 0 1" << endl;
            else cout << -1 << endl;
        } else {
            if (a >= 1) cout << a-1 << " 1 0" << endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}
