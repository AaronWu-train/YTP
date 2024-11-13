#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define AI(x) begin(x),end(x)
#ifdef DEBUG
#define debug(args...) LKJ("[ "+string(#args)+" ]", args)
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
        int n,m;
        cin >> n >> m;
        int xa, xb, xc, xd, ya, yb, yc, yd;
        cin >> xa >> ya;
        cin >> xb >> yb;
        cin >> xc >> yc;
        cin >> xd >> yd;
        int smx, smy, lrx, lry;
        if (xa > xb) {
            swap(xa, xb);
            swap(ya, yb);
        }
        if (xc > xd) {
            swap(yc, yd);
            swap(xc, xd);
        }
        smx = max(min(xa, xb), min(xc, xd));
        smy = max(min(ya, yb), min(yc, yd));
        lrx = min(max(xa, xb), max(xc, xd));
        lry = min(max(ya, yb), max(yc, yd));
        if (smx > lrx || smy > lry) {
            cout << 0 << endl;
            continue;
        }
        
        if (ya <= smy && yc <= smy) {
            cout << (lry - smy) + (lrx - smx) + 1 << endl;
        }else {
            cout << max((lry - smy),(lrx - smx)) + 1 << endl;
        }
        
        
    }
    
    return 0;
}
