#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1005, MAXM = 5005, MAXW = 1e9 + 7;
int color[MAXN][2];

struct Edge {
    int u, v, w;
} e[MAXM];
vector<int> graph[MAXN];
void dfs(int u, bool c) {
    color[u][c] = 1;
    for(auto v : graph[u]) {
        if(!color[v][c]) dfs(v, c);
    }
    color[u][c] = 2;
}
int n, m, q;
bool check(int k, int x, int y) {
    for(int i = 1; i <= n; ++i) {
        graph[i].clear();
        color[i][0] = color[i][1] = 0;
    }
    for(int i = 0; i < m; ++i) {
        auto [u, v, w] = e[i];
        if(k >= w) {
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    dfs(x, 0); // to
    dfs(y, 1); // back
    for(int i = 0; i < m; ++i) {
        auto [u, v, w] = e[i];
        if(color[u][0] && color[v][1]) return 1;
        if(color[v][0] && color[u][1]) return 1;
    }
    return 0;
}
void solve() {
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i) {
        auto& [u, v, w] = e[i];
        cin >> u >> v >> w;
    }
    for(int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        int l = -1, r = MAXW;
        while(r - l > 1) {
            int mid = (l + r) >> 1;
            if(check(mid, x, y)) r = mid;
            else l = mid;
        }
        if(r == MAXW) cout << "-1\n";
        else cout << r << '\n';
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
