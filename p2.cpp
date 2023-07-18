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

signed main(){_
	ll n, w;
	cin >> n >> w;
	vector<ll> a(n), b(n), c(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}
	ll ans = 0;
	for (auto &i : a) ans += i;
	for (auto &i : b) ans += i;
	debug(ans);

	vector<ll> dp(w+5);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= w; ++j) {
			if (j >= c[i]) {
				dp[j] = max(dp[j], dp[j-c[i]] + a[i]);
			}
			debug(i, j, dp[j]);
		}
	}
	cout << ans + dp[w] << endl;
	return 0;
}
