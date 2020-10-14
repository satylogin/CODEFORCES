#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t, n;
    vector<int> A(200005);
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << 2 << endl;
            cout << "1 2" << endl;
            continue;
        }
        cout << 2 << endl;
        cout << n << " " << n-2 << endl;
        cout << n-1 << " " << n-1 << endl;
        n = n-1;
        while (n > 2) {
            cout << n << " " << n-2 << endl;
            n = n - 1;
        }
    }

    return 0;
}
