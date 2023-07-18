#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
int a[MAXN], presum[MAXN], sufmx[MAXN], premx[MAXN];
struct Node {
    int mx, mn;
    Node(){}
    Node(int val): mx(val), mn(val) {}
    Node operator + (const Node& that) {
        Node ret;
        ret.mx = max(mx, that.mx);
        ret.mn = min(mn, that.mn);
        return ret;
    }
} seg[MAXN << 2];
int n;
void pull(int v) {
    seg[v].mx = max(seg[v << 1].mx, seg[v << 1 | 1].mx);
    seg[v].mn = min(seg[v << 1].mn, seg[v << 1 | 1].mn);
}
void build(int l = 1, int r = n, int v = 1) {
    if(l == r) {
        seg[v] = Node(presum[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, v << 1);
    build(mid + 1, r, v << 1 | 1);
    pull(v);
}
Node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if(ql == l && qr == r) return seg[v];
    int mid = (l + r) >> 1;
    if(qr <= mid) return query(ql, qr, l, mid, v << 1);
    if(ql > mid) return query(ql, qr, mid + 1, r, v << 1 | 1);
    return query(ql, mid, l, mid, v << 1) + query(mid + 1, qr, mid + 1, r, v << 1 | 1);
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        presum[i] = presum[i - 1] + a[i];
    }
    build();
    for(int i = 1; i <= n; ++i) {
        if(i == 1) {
            auto ans = query(1, n);
            cout << min(ans.mn, 0) << ' ' << max(ans.mx, 0) << '\n';
            continue;
        }
        auto back = query(i, n);
        auto front = query(1, i - 1);
        int mx = max(max(back.mx, presum[n] + front.mx) - presum[i - 1], 0);
        int mn = min(min(back.mn, presum[n] + front.mn) - presum[i - 1], 0);
        cout << mn << ' ' << mx << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
