#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

struct MinTime {
    typedef pair<long long, pair<int, int>> node;
    
    multiset<node> incremental_cost;

    long long get_cost(int len, int partitions) {
        int w = len / partitions;
        int b = len % partitions;
        int a = partitions - b;

        return 1ll * a * w * w + 1ll * b * (w + 1ll) * (w + 1ll);
    }

    void insert(int x) {
        incremental_cost.insert({get_cost(x, 2), {x, 1}});
    }

    void extract() {
        node elem = *incremental_cost.rbegin();
        incremental_cost.erase(--incremental_cost.end());
        int length = elem.second.first;
        int partitions = elem.second.second + 1;
        incremental_cost.insert({get_cost(length, partitions) - get_cost(length, partitions + 1), {length, partitions}});
    }

    long long solution() {
        long long ans = 0;
        for (node n: incremental_cost) {
            ans += get_cost(n.second.first, n.second.second);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    MinTime min_time;
    int n, k, i, x;
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> x;
        min_time.insert(x);
    }
    while (n < k) {
        n++;
        min_time.extract();
    }
    cout << min_time.solution() << endl;

    return 0;
}
