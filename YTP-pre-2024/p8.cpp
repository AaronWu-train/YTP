#include<bits/stdc++.h>
typedef pair<int, int> pii;
typedef pair<int, pii> pi_ii;

struct DisjointSet {
    vector<int> master;

    DisjointSet(int vertexCount) {
        master.resize(vertexCount);
        iota(master.begin(), master.end(), 0);
    }

    int query(int a) {
        if (a == master[a]) return a;

        return master[a] = query(master[a]);
    }

    bool connected(int a, int b) {
        return query(a) == query(b);
    }

    void merge(int a, int b) {
        master[query(a)] = master[b];
    }
};

int kruskal(vector<pi_ii>& minEdge, DisjointSet& ds) {
    int cost = 0;
    
    for (auto& [w, uv]: minEdge) {
        auto& [u, v] = uv;

        if (ds.connected(u, v)) continue;

        ds.merge(u, v);
        cost += w;
    }

    return cost;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    DisjointSet ds(vertexCount);

    vector<pi_ii> minEdge(edgeCount);
    for (auto& [w, uv]: minEdge) {
        auto& [u, v] = uv;
        cin >> u >> v >> w;
	}
    
    sort(minEdge.begin(), minEdge.end());
	for(int i=0; i<n; i++)
    cout << kruskal(minEdge, ds) << '\n';
}

