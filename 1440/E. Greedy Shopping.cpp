#include <bits/stdc++.h>
 
using namespace std;
 
#define MOD 1000000007
#define EPS 1e-9

struct Node {
    int _min;
    int _max;
    long long _sum;
    long long _lazy;

    Node(int _min, int _max, long long _sum, long long _lazy) {
        this->_min = _min;
        this->_max = _max;
        this->_sum = _sum;
        this->_lazy = _lazy;
    }

    Node() {}
};

struct Child {
    int left, right;

    Child(int left, int right) {
        this->left = left;
        this->right = right;
    }
};

Child get_child(int n) {
    return Child(n<<1, (n<<1)|1);
}

const int N = 2e5;
const int LIM = 2e6;
Node tree[LIM];
int A[N+5];

void update_node(int n, Child &child) {
    tree[n] = Node(
        min(tree[child.left]._min, tree[child.right]._min),
        max(tree[child.left]._max, tree[child.right]._max),
        tree[child.left]._sum + tree[child.right]._sum,
        0
    );
}

void create(int n, int start, int end) {
    if (start == end) {
        tree[n] = Node(A[start], A[start], A[start], 0);
    } else if (start < end) {
        int mid = (start + end) >> 1;
        Child child = get_child(n);
        create(child.left, start, mid);
        create(child.right, mid+1, end);
        update_node(n, child);
    }
}

void update_lazy(int n, int len, int v) {
    if (n < LIM) {
        tree[n] = Node(v, v, 1ll * v * len, v);
    }
}

void shift(int n, int start, int end) {
    if (!tree[n]._lazy) {
        return;
    }
    int mid = (start + end) >> 1;
    Child child = get_child(n);
    update_lazy(child.left, mid - start + 1, tree[n]._lazy);
    update_lazy(child.right, end - mid, tree[n]._lazy);
    tree[n]._lazy = 0;
}

void insert(int n, int start, int end, int lim, int v) {
    if (start > lim or v <= tree[n]._min) {
        return;
    }
    shift(n, start, end);
    if (end <= lim and tree[n]._max <= v) {
        update_lazy(n, end - start + 1, v);
        return;
    }
    int mid = (start + end) >> 1;
    Child child = get_child(n);
    insert(child.left, start, mid, lim, v);
    insert(child.right, mid + 1, end, lim, v);
    update_node(n, child);
}

pair<int, int> query(int n, int start, int end, int begin, int money) {
    if (end < begin or start > end or tree[n]._min > money) { 
        return {0, 0};
    }
    shift(n, start, end);
    if (start >= begin and tree[n]._sum <= money) {
        return {end - start + 1, (int)tree[n]._sum};
    }
    int mid = (start + end) >> 1;
    Child child = get_child(n);
    pair<int, int> left_consume = query(child.left, start, mid, begin, money);
    pair<int, int> right_consume = query(child.right, mid + 1, end, begin, money - left_consume.second);
    
    return {
        left_consume.first + right_consume.first, 
        left_consume.second + right_consume.second
    };
}

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    int n, q, i, x, y, z;
    cin >> n >> q;
    for (i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    create(1, 1, n);
    while (q--) {
        cin >> z >> x >> y;
        if (z == 1) {
            insert(1, 1, n, x, y);
        } else {
            cout << query(1, 1, n, x, y).first << endl;
        }
    }

    return 0;
}
