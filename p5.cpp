#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG 
#define debug(args...) LKJ("\033[1;32m[ "+string(#args)+" ]\033[0m", args)
template<class I> void LKJ(I&&x){ cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t){ cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b){ while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
#define _ ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
struct node {
	int t;
	int v;
};

struct DSU {
	vector<vector<node>> fa;
	vector<int> sz;

	void init(int n) {
		fa.resize(n+5);
		sz.resize(n+5, 1);
		for (int i = 0; i <= n; ++i) {
			fa[i].push_back({0, i});
		}
	}

	int query(int x, int tt) {
		int l = 0, r = fa[x].size();
		while (r - l > 1) {
			int mid = (l + r)/2;
			if (fa[x][l].t > tt) {
				r = mid;
			} else {
				l = mid;
			}
		}
		if (fa[x][l].v == x) return x;
		return query(fa[x][l].v, tt);
	}
	void merge (int a, int b, int tt) {
		int ka = query(a, tt);
		int kb = query(b, tt);
		if (sz[ka] > sz[kb]) swap(ka, kb);
		fa[ka].push_back({kb, tt});
	}
}djs;


signed main(){_
	int n, q;
	cin >> n >> q;
	
	djs.init(n);

	for (int i = 1; i <= q; ++i){
		int tp;
		cin >> tp;
		if (tp == 1) {
			int a, b; cin >> a >> b;
			djs.merge(a, b, i);
		}	
		if (tp == 2){
			int k;
			cin >> k;
			vector<int> asks;
			for (int j = 0; j < k; ++j) {
				int a; cin >> a;
				asks.push_back(a);
			}

			int ma = djs.query(asks[0], i);
			bool ns = 0;
			for (auto &j : asks) {
				if (ma != djs.query(j, i)){
					ns = 1;
					break;
				}
			}
			if (ns) {
				cout << -1 << endl;
				continue;
			} 

			int l = 0, r = i;
			while (l < r) {
				int mid = (l + r) / 2;
				bool ns = 1;
				int ra = djs.query(asks[0], l);
				for (auto &j : asks) {
					if (ra != djs.query(j, l)){
						ns = 0;
						break;
					}
				}
				if (ns) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			cout << l << endl;
		}
	}
	return 0;
}
