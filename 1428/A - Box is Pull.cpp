#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    long long t, x1, y1, x2, y2;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2;
        long long ans = abs(x1 - x2) + abs(y1 - y2);
        int diff = (x1 != x2) + (y1 != y2);
        if (diff == 2) ans += 2;
        cout << ans << endl;
    }

    return 0;
}
