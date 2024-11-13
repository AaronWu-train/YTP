#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
const int MAXN = 2e5 + 5;
int arr[MAXN];
bool color[MAXN];
pair<int, int> p[MAXN];
//map<int, pair<int, int> > mp; // [l, [r, val]]
struct DSU {
	int rk[MAXN], rt[MAXN], mn[MAXN];
	DSU(int N) {
		for(int i = 1; i <= N; ++i) {
			rk[i] = 1;
			rt[i] = i;
			mn[i] = arr[i];
		}
	}
	int find(int k) {
		if(rt[k] == k) return k;
		return rt[k] = find(rt[k]);
	}
	void setunion(int k1, int k2) {
		int r1 = find(k1), r2 = find(k2);
		if(rk[r1] > rk[r2]) {
			rt[r2] = r1;
			rk[r1] += rk[r2];
			mn[r1] = min(mn[r1], mn[r2]);
		} else {
			rt[r1] = r2;
			rk[r2] += rk[r1];
			mn[r2] = min(mn[r1], mn[r2]);
		}
	}
	int getrk(int k) {
		int r = find(k);
		return rk[r];
	}
	int getmn(int k) {
		int r = find(k);
		return mn[r];
	}
};
void solve() {
	int N;
	cin >> N;
	for(int i = 1; i <= N; ++i) {
		cin >> arr[i];	
		p[i].first = arr[i];
		p[i].second = i;
	}	
	sort(p + 1, p + N + 1, greater<pair<int,int> >());
	long long int mx = 0;
	DSU dsu(N);
	long long int cur = 0;
	for(int i = 1; i <= N; ++i) {
		auto pos = p[i].second;
		//cerr << pos << ' ';
		color[pos] = 1;
		if(color[pos + 1]) {
			cur -= 1ll * dsu.getrk(pos + 1) * dsu.getmn(pos + 1);
			dsu.setunion(pos, pos + 1);
			//cerr << cur << ' ';
		}	
		if(color[pos - 1]) {
			cur -= 1ll * dsu.getrk(pos - 1) * dsu.getmn(pos - 1);
			dsu.setunion(pos, pos - 1);
			//cerr << cur << ' ';
		}	
		cur += 1ll * dsu.getrk(pos) * dsu.getmn(pos);
		//cerr << cur << '\n';
		mx = max(mx, cur);
	}
	cout << mx << '\n';
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
}
