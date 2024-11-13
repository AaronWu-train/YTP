#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
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

struct SegmantTree{
    struct node{
        ll up = 0;
        ll len = 1;
        ll tag = 0;
        void flip(int k) {
            if (k % 2) {
                tag++;
                up = len - up;
                tag %= 2;
            }
        }
    };
    int n;
    vector<node> arr;
    void init (int _n, string s) {
        n = _n;
        arr.resize(2*n+5);
        for (int i = 0; i < n; ++i) {
            arr[n+i].up = (s[i]=='1');
        }
        for (int i = n-1; i > 0; --i) {
            arr[i].len = arr[2*i].len + arr[2*i+1].len;
            arr[i].up = arr[2*i].up + arr[2*i+1].up;
        }
    }
    void pull(int x) {
        if (x==0) return;
        pull(x/2);
        if (arr[x/2].tag % 2) {
            arr[x].flip(arr[x/2].tag);
            arr[x^1].flip(arr[x/2].tag);
            
        }
        arr[x/2].tag = 0;
    }
    void push(int x) {
        x /= 2;
        while (x) {
            arr[x].up = arr[x*2].up + arr[x*2 + 1].up;
            x/=2;
        }
    }
    void modify(int l, int r) {
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                arr[l].flip(1);
                push(l);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                arr[r].flip(1);
                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
    }
    ll query(int l, int r) {
        int ans = 0;
        l += n;
        r += n;
        while (l < r) {
            if (l & 1) {
                pull(l);
                ans += arr[l].up;
                push(l);
                l++;
            }
            if (r & 1) {
                --r;
                pull(r);
                ans += arr[r].up;
                push(r);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;
    }
}seg;


signed main(){_
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    seg.init(n, s);
    while (q--) {
        ll tp, l , r;
        cin >> tp >> l >> r;
        if (tp == 1) {
            seg.modify(l-1, r);
        }
        else {
            ll ret = seg.query(l-1, r);
            cout << (r - l + 1 - ret) * ret << endl;
        }
    }
    
    
    return 0;
}
