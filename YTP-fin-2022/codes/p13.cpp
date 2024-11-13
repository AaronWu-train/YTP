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
    if (n % 2) {
        cout << -1 << endl;
        return 0;
    }
    cout << (n/2) * (n/2) << endl;
    for (int i = 1; i <= n; i+=2) {
        cout << i << " " << i+1 << endl;
        for (int j = 1; j < i; ++j) {
            cout << j << " " << i << endl;
        }
    }
    return 0;
}
