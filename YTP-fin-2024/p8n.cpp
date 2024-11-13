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
vector<bool> elim(MAXN, 0);
vector<int> ans;
void re(int root, int pa){
	for(auto x:g[root]){
		if(x==pa) continue;
		if(elim[x]) continue;
		elim[x]=true;
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
			elim[i]=1;
			re(i,pt[i]);
		}
	}
	int as=0;
	for(int i=1; i<=n; i++){
		if(!elim[i]&&g[i].size()==1) as++;
	}cout<<as<<'\n';
	for(int i=1; i<=n; i++){
		if(!elim[i]&&g[i].size()==1) cout<<i<<' ';
	}
	return 0;
}
