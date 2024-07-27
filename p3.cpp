#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
#define MAXN 200007
vector<pii> sub(MAXN,{1,1});
vector<int> heavy(MAXN,1);
vector<vector<pii>> t(MAXN);

vector<pii> pr;
void recur(int root, int pa,int val){
	bool leaf=true;
	for(auto [v,w]:t[root]){
		if(v==pa) continue;
		sub[v]={sub[root].ff,val+w};
		if(v!=heavy[root]) sub[v].ff++;
		leaf=false;
		recur(v,root,val+w);
	}
	if(leaf) pr.pb(sub[root]);
}

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;cin>>n;
	for(int i=0; i<n-1; i++){
		int a,b,c;cin>>a>>b>>c;
		t[a].pb({b,c});
		t[b].pb({a,c});
	}
	for(int i=1; i<=n; i++)cin>>heavy[i];
	sub[1]={0,0};
	recur(1,1,0);
	sort(all(pr));
	int pt=0;
	int sm=1e18;
	for(int i=0; i<n; i++){
		if(pt<pr.size()){
			sm=min(sm,pr[pt].ss);
			if(pr[pt].ff<i) {
				pt++;
				if(pt<pr.size()){
					sm=min(sm,pr[pt].ss);}
			}}
		cout<<sm<<'\n';

	}

}
