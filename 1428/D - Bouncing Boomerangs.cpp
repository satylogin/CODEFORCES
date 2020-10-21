#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int n;
    vector<int> targets_hit(100005);
    vector<pair<int, int>> targets;
    queue<pair<int, int>> indices[4];

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> targets_hit[i];
    }
    int available_row = n;
    bool valid_configuration = true;
    for (int i = n; i >= 1; --i) {
        if (targets_hit[i] == 1) {
            targets.push_back({available_row, i});
            indices[1].push({available_row--, i});
        } else if (targets_hit[i] == 2) {
            if (indices[1].size() == 0) {
                valid_configuration = false;
                break;
            }
            pair<int, int> available = indices[1].front();
            indices[1].pop();
            targets.push_back({available.first, i});
            indices[2].push({available.first, i});
        } else if (targets_hit[i] == 3) {
            bool found_target = false;
            for (int index = 3; index >= 1; --index) {
                if (!indices[index].size()) {
                    continue;
                }
                found_target = true;
                pair<int, int> available = indices[index].front();  
                indices[index].pop();
                targets.push_back({available_row, i});
                targets.push_back({available_row, available.second});
                indices[3].push({available_row--, i});
                break;
            }
            if (!found_target) {
                valid_configuration = false;
                break;
            }
        }
    }
    if (valid_configuration) {
        cout << targets.size() << endl;
        for (pair<int, int> target: targets) {
            cout << target.first << " " << target.second << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
