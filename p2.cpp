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
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &i : arr) cin >> i;
	sort(AI(arr));
	ll r = n-1;
	ll ans = LLONG_MAX;
	for (ll l = 0; l < n; ++l) {
		 while (r > 0 && abs(k - arr[l]*arr[r]) >= abs(k - arr[l]*arr[r-1])) {
			 ans = min(ans, abs(k - arr[l]*arr[r]));
			 ans = min(ans, abs(k - arr[l]*arr[r-1]));
			 ans = min(ans, abs(k - arr[l+1]*arr[r-1]));
			 r--;
		}
		ans = min(ans, abs(k - arr[l]*arr[r]));
	}
	cout << ans << endl;

	return 0;
}
