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
    int n;
    cin >> n;
    if (n == 1) {
        double x, y;
        cin >> x >> y;
        cout << x << " "<< y << " "<< 0<<endl;
        cout <<"0 0 0\n";
        cout <<"0 0 0\n";
        cout << "1\n";
    }
    if (n == 2) {
        double x, y, a, b;
        cin >> x >> y >> a >> b;
        cout << (x + a)/2.0<< " "<< (y+b)/2.0 << " ";
        cout << sqrt((x-a)*(x-a)+(y-b)*(y-b))/2.0 << endl;
        
        
        cout <<"0 0 0\n";
        cout <<"0 0 0\n";
        cout << "11\n";
    }
    else {
        vector<ll> x(n+5);
        vector<ll> y(n+5);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }
        ll d1 = (x[2]*x[2] + y[2]*y[2]) -  (x[1]*x[1] + y[1]*y[1]);
        ll d2 = (x[3]*x[3] + y[3]*y[3]) -  (x[2]*x[2] + y[2]*y[2]);
        ll k = 2 * ((y[3] - y[2]) * (x[2] - x[1]) - ((y[2] - y[1])*(x[3] - x[2]) ));
        double fx = (long double)((y[3] - y[2]) * d1 - (y[2]-y[1])*d2)/k;
        double fy = (long double)((x[2] - x[1]) * d2 - (x[3] - x[2]) *d1)/k ;
        double r = sqrt((fx-x[1])*(fx-x[1]) + (fy-y[1])*(fy-y[1]));
        cout << fx << " " << fy << " " << r << endl;
        cout <<"0 0 0\n";
        cout <<"0 0 0\n";
        for (int i = 1; i <= n; ++i) cout << 1;
        cout << endl;

    }
    
    return 0;
}
