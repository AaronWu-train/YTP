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
#define MAXN 200007
vector<vector<int>> g(MAXN+1);
vector<int> pt(MAXN+1);
vector<bool> pd(MAXN+1,0);
vector<int> ans;
void re(int root, int pa){
	debug(root);
	if(g[root].size()==1) {ans.pb(root);return;}
	if(pt[root]){
		re(pt[root],root);
		return;
	}
	for(auto x:g[root]){
		if(x==pa) continue;
		if(pt[x]==root) continue;
		re(x,root);
	}
}



signed main(){//_
	int n;cin>>n;
	for(int i=0; i<n-1; i++){
		int a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i=1; i<=n; i++){
		cin>>pt[i];
		pd[pt[i]]=1;
	}
	for(int i=1; i<=n; i++){
		if(pt[i]!=0){
			re(i,i);
			break;
		}
	}
	cout<<ans.size()<<'\n';
	for(auto x:ans) cout<<x<<' ';
	return 0;
}
