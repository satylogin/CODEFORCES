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
        set<char> single_dir_conveyer;
        set<int> returnable_rooms;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '-') {
                returnable_rooms.insert(i);
                returnable_rooms.insert((i + 1) % n);
            } else {
                single_dir_conveyer.insert(s[i]);
            }
        }
        cout << (single_dir_conveyer.size() < 2 ? n : returnable_rooms.size()) << endl;
    }

    return 0;
}
