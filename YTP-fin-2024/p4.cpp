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
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		string s; cin >> s;
		int f1 = 0, f2 = 0;
		if (s[0] == 'L'){ cout << -1 << endl; continue;}
		bool flag = 0;
		for (int i = 1; i < n; ++i) {
			int k = (s[i] == 'R');
			if ((f1 & 1) == k) {
				f1++;
			}
			else if ((f2 & 1) == k) {
				f2++;
			}
			else {
				cout << -1 << endl;
				flag = 1;
				break;
			}
		}
		if (flag) continue;
		cout << f1+1 << endl;
	}

	return 0;
}
