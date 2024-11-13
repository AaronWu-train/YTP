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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> arr(n+5);
	for (int i = 1; i < n; ++i) {
		if (s[i] == s[i-1] || (s[i-1] == '9' && s[i] == '4')) {
			arr[i]++;
		}
		arr[i] += arr[i-1];
	}
	OI(AI(arr));

	int q;
	cin >> q;
	while (q--) {
		int l, r; 
		cin >> l >> r;
		int k = arr[r-1] - arr[l-1];
		if (k == 0) cout << -1 << endl;
		else {
			cout << 2 << " " << k << endl;
		}
	}	

	return 0;
}
