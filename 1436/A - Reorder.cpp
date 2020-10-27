#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t, n, m, x, s, i;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        s = 0;
        for (i = 0; i < n; ++i) {
            cin >> x;
            s += x;
        }
        cout << (s == m ? "YES" : "NO") << endl;
    }

    return 0;
}
