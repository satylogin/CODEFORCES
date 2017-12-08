#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

const ld eps = 1e-9;

class Point {
	public:
		ll x, y;
		bool operator < (Point b) {
			if (y != b.y) return y < b.y;
			return x < b.x;
		}
};

Point pivot, A[1000001], hull[1000001], B[1000001];
int N, M, len;
ld dot[1000001];

int ccw(Point a, Point b, Point c) {
	ll area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
	if (area > 0) return -1;
	if (area < 0) return  1;
	return 0;
}

ll dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool polar_order(Point a, Point b) {
	int order = ccw(pivot, a, b);
	if (order == 0) return dist(pivot, a) < dist(pivot, b);
	return (order == -1);
}

void convex_hull() {
	if (N < 3) return;
	int ans = 0;
	for (int i = 1; i < N; ++i) if (A[i] < A[ans]) ans = i;
	swap(A[0], A[ans]);
	pivot = A[0];
	sort(A+1, A+N, polar_order);
	hull[len++] = A[0];
	hull[len++] = A[1];
	hull[len++] = A[2];
	for (int i = 3; i < N; ++i) {
		while (len > 2 && ccw(hull[len-2], hull[len-1], A[i]) != -1) len--;
		hull[len++] = A[i];
	}
}

bool inside(Point a, Point b, Point c, Point p, int e1, int e2, int e3) {
	int o1 = ccw(a, b, p);
	int o2 = ccw(b, c, p);
	int o3 = ccw(c, a, p);
	bool s1 = e1 ? o1 == -1 : o1 != 1;
	bool s2 = e2 ? o2 == -1 : o2 != 1;
	bool s3 = e3 ? o3 == -1 : o3 != 1;
	return (s1 and s2 and s3);
}

bool check() {
	Point ref;
	ref.x = pivot.x + 1;
	ref.y = pivot.y;
	for (int i = 1; i < len; ++i) {
		dot[i] = atan2(hull[i].y - pivot.y, hull[i].x - pivot.x);
	}
	for (int i = 0; i < M; ++i) {
		ld tmp = atan2(B[i].y - pivot.y, B[i].x - pivot.x);
		int start = 1;
		int end = len-2;
		int vec = -1;
		while (start <= end) {
			int mid = (start + end) >> 1;
			if (dot[mid] <= tmp) {
				vec = mid;
				start = mid + 1;
			} else {
				end = mid - 1;
			}
		}
		if (vec != -1) {
			if (!inside(pivot, hull[vec], hull[vec+1], B[i], vec == 1 ? 1 : 0, 1, vec == len-2 ? 1 : 0)) return false;
		} else {
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

	int i;
	cin >> N;
	for (i = 0; i < N; ++i) cin >> A[i].x >> A[i].y;
	cin >> M;
	for (i = 0; i < M; ++i) cin >> B[i].x >> B[i].y;
	convex_hull();
	if (check()) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}
