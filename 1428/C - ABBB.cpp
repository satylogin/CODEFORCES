#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        stack<char> chars;
        for (char c: s) {
            if (chars.empty() or c == 'A') {
                chars.push(c);
            } else {
                chars.pop();
            }
        }
        cout << chars.size() << endl;
    }

    return 0;
}
