#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#define int long long
#define pii pair<int, int>
using namespace std;
__int128 read() {
    __int128 x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct fundamental{
    int low, upreal, upi, upsqrt;
    fundamental(int a1,int b1,int c1, int d1): low(a1), upreal(b1), upi(c1), upsqrt(d1){};
};

int ff(int tmp){
    if(tmp>0) return 1;
    else return -1;
}

struct cmp {
    bool operator () (const fundamental &aa,const fundamental &bb){
        int gcdlow=__gcd(abs(aa.low), abs(bb.low));
        int gcdupreal=__gcd(abs(aa.upreal), abs(bb.upreal));
        int gcdupi=__gcd(abs(aa.upi), abs(bb.upi));
        int gcdsqrt=__gcd(abs(aa.upsqrt), abs(bb.upsqrt));
        if(aa.low*bb.upreal!=aa.upreal*bb.low) return true;
        if((aa.low/gcdlow)*(aa.low/gcdlow))
        if(ff(aa.low)*aa.low*aa.low*bb.upsqrt!=aa.upsqrt*bb.low*bb.low*ff(bb.low)) return true;
        if(ff(aa.low)*aa.low*aa.low*bb.upi!=aa.upi*bb.low*bb.low*ff(bb.low)) return true;
        return false;
    }
};

bool operator < (const fundamental &aa,const fundamental &bb){
        if(aa.low*bb.upreal*aa.low*bb.upreal!=aa.upreal*bb.low*aa.low*bb.upreal) return true;
        if(ff(aa.low)*aa.low*aa.low*bb.upsqrt!=aa.upsqrt*bb.low*bb.low*ff(bb.low)) return true;
        if(ff(aa.low)*aa.low*aa.low*bb.upi!=aa.upi*bb.low*bb.low*ff(bb.low)) return true;
        return false;
    }
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    signed T;cin>>T;
    
    while(T--){
        signed N;cin>>N;
        set<fundamental> ans;
        int a, b, c;
        for(int i=0; i<N; i++){
            a=read();b=read();c=read();
            if(a==0&&b==0){
                continue;
            }
            if(a==0){
                ans.insert(fundamental(b, c*-1, 0, 0));
                continue;
            }
            int sqq=0, iii=0, sqrtd=0;
            int tmp=b*b-4*a*c;
            int tpp=sqrt(tmp);
            if(tmp<0) iii=-1*tmp;
            else {
                if(tpp*tpp==tmp){
                    sqrtd=tpp;
                    sqq=0;
                }else{
                    sqq=tmp;
                    }
                }
            ans.insert(fundamental(2*a, -1*b+sqrtd, iii, sqq));
            ans.insert(fundamental(2*a, -1*b-sqrtd, -1*iii, -1*sqq));
        }cout<<ans.size()<<'\n';
        /*for(fundamental x:ans){
            cout<<x.low<<' '<<x.upreal<<' '<<x.upsqrt<<' '<<x.upi<<'\n';
        }*/
    }
}