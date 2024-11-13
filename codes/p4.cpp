#include <iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1005;
ll x1[MAXN], y1[MAXN], x2[MAXN], y2[MAXN];
bool in(ll px, ll py, ll cx, ll cy, ll r) {
	return ((px - cx) * (px - cx)) <= r * r - (py - cy) * (py - cy);	
}
void solve() {
	int N, M;
	cin >> N >> M;
	for(int i = 0; i < N; ++i) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];	
	}
	for(int j = 0; j < M; ++j) {
		ll x, y, r;
		cin >> x >> y >> r;
		ll cnt = 0;
		for(int i = 0; i < N; ++i) {
			ll dx, dy;
			if(x <= x2[i] && x >= x1[i] && y >= y1[i] && y <= y2[i]) {
				++cnt;
				continue;
			}
			if(abs(x - x1[i]) <= r) {
				dx = x;
				if(y < y1[i]) dy = y1[i];
				else if(y > y2[i]) dy = y2[i];	
				else dy = y;
				if(in(dx, dy, x, y, r)) {
					++cnt;
					continue;
				}
			}	
			if(abs(x - x2[i]) <= r) {
				dx = x;
				if(y < y1[i]) dy = y1[i];
				else if(y > y2[i]) dy = y2[i];	
				else dy = y;
				if(in(dx, dy, x, y, r)) {
					++cnt;
					continue;
				}
			}	
			if(abs(y - y1[i]) <= r) {
				dy = y;
				if(x < x1[i]) dx = x1[i];
				else if(x > x2[i]) dx = x2[i];	
				else dx = x;
				if(in(dx, dy, x, y, r)) {
					++cnt;
					continue;
				}
			}	
			if(abs(y - y2[i]) <= r) {
				dy = y;
				if(x < x1[i]) dx = x1[i];
				else if(x > x2[i]) dx = x2[i];	
				else dx = x;
				if(in(dx, dy, x, y, r)) {
					++cnt;
					continue;
				}
			}	
		}
		cout << cnt << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	solve();
}
