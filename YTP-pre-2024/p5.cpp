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

const ll mod = 998244353;

ll mpow(ll a, ll n) {
	ll ans = 1;
	for (int i = 1; i <= n; i <<= 1) {
		if (i & n) ans = a * ans % mod;
		a = a*a%mod;
	}
	return ans%mod;
}

ll mdiv(ll a, ll b) {
	a = (a%mod + mod)%mod;
	b = (b%mod + mod)%mod;
	ll k = mpow(b, mod-2);
	return a * k % mod;	
}

signed main(){_
	ll m, n, p, q;
	cin >> m >> n >> p;
	q = 100-p;
	if (p == 0) {
		cout << 0 << endl;
	}
	else if (p == q) {
		cout << mdiv(m, m+n) << endl;
	}
	else {
		auto k = mdiv(q, p);
		auto a1 = mpow(k, m);
		auto a2 = mpow(k, m+n);
		ll ans = mdiv(a1-1, a2-1);
		cout << ans << endl;
	}


	return 0;
}
