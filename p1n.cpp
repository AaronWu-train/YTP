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
	cin>>s;
	int len=s.size();
	int ind=-1;
	//find 1
	for(int i=0;i<len;i++){
		if(s[i]=='1'){
			ind=i;
			break;
		}
	}
	if(ind==-1){
		cout<<0<<endl;
		return 0;
	}
	//create string 2
	string s2;
	s2.push_back('2');
	for(int i=0;i<len-ind-1;i++){
		s2.push_back('0');
	}
	debug(s2);


	//minus
	int l2=s2.length();
	string s3;
	for (int i = ind; i < len; ++i) {
		s3.push_back(s[i]);
	}
	for(int i=l2-1; i>=0; i--){
		if(s3[i] > s2[i]){
			s2[i-1]--;
			s2[i] = '0' + (10) + (s2[i]-'0') - (s3[i]-'0');
		}
		else{
			s2[i] -= (s3[i]-'0');
		}
	}
	//cout string 2

	bool isnt_0 = 0;
	for(int i=0;i<l2;i++){
		if(s2[i]!='0') isnt_0 = 1;
		if(isnt_0) cout << s2[i];
	}
	cout << endl;
	return 0;
}
