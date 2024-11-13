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
	string s;
	cin >> s;
	int n = s.size();
	vector<int> arr(n);
	int cool=2;
	int det=-1;
	for(int i=0; i<n; i++){
		if(s[i]=='1'){
			det=i;
			break;
		}
	}
	if(det==-1){cout<<0;return 0;}
	if(det==n-1){cout<<1;return 0;}
	int give=false;
	vector<char> ans;
	for(int i=n-1; i>=det; i--){
		int tmp=s[i]-'0';
		if(give){
			tmp++;
		}
		ans.pb((10-tmp)%10+'0');
		if(tmp==0) give=true;
		else give=true;
	}
	for(int i=ans.size()-1; i--; i>=0) cout<<ans[i];
	return 0; 
}
