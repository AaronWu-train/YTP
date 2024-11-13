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
#define int ll

struct ege{
	ll w, id, a, b;
};

struct DSU {
	int n;
	vector<int> arr;
	vector<int> sz;
	DSU (int _n) {
		n = _n;
		arr.resize(n+5, 0);
		sz.resize(n+5, 1);
		for (int i = 0; i <= n; ++i) {
			arr[i] = i;
		}
	}

	int query (ll a) {
		if (arr[a] == a) return a;
		arr[a] = query(arr[a]);
		return arr[a];
	}
	
	void modify(int a, int b) {
		int fa = query(a);
		int fb = query(b);
		if (sz[fa] < sz[fb]) swap(fa, fb);
		arr[fb] = fa;
		sz[fa] += sz[fb];
	}
};


signed main(){_
	int n, m;
	cin >> n >> m;
	vector<ege> arr(n);
	for (int i = 0; i < m; ++i) {
		cin >> arr[i].a >> arr[i].b >> arr[i].w;
		arr[i].id = i+1;
	}
	auto brr = arr;
	for (int i = 0; i < m; ++i) {
		DSU djs(m);
		djs.modify(brr[i].a, brr[i].b);
		ll ans = brr[i].w;
		sort(AI(arr), [](auto &x, auto &y){
				return x.w < y.w;
				});

		for (auto &j : arr) {
			if (djs.query(j.a) != djs.query(j.b)){
				ans += j.w;
				djs.modify(j.a,j.b);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
