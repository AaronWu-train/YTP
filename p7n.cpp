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
vector<int>dp, visited[1<<18];
int arr[19][19];
int fuck(int x) {
	if (visited[x ] || x == 0){
		return 0;
	}
	for (int i = 1; i <(1<<18); i <<= 1) {
		for (int j = i<<1; j<(1<<18); j <<= 1){
			dp[x] = min(dp[x], fuck(x^i^j));
		}
	}
}



signed main(){_
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int
	}

	
	return 0;
}
