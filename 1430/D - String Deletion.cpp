#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t, n;
    string s;

    cin >> t;
    while (t--) {
        cin >> n >> s;
        int i = 0, j = 0, k, op = 0, completed = 0;
        while (i < n) {
            k = 0;
            while (completed == 0 and j < n and (s[j] == '#' or s[j] != s[j+1])) {
                j++;
            }
            if (j == n and completed == 0) {
                completed = 1;
                j = i;
            }
            if (completed == 0 and j < n and s[j] == s[j+1]) {
                s[j] = '#';
                k = 1;
            } else if (completed == 1) {
                while (j < n and s[j] == '#') {
                    j += 1;
                }
                if (j < n) {
                    s[j] = '#';
                    k = 1;
                }
            }
            while (i < n and s[i] == '#') {
                i++;
            }
            if (i < n) {
                char c = s[i];
                while (i < n and s[i] == c) {
                    s[i] = '#';
                    i += 1;
                }
                k = 1;
            }
            op += k;
        }
        cout << op << endl;
    }

    return 0;
}
