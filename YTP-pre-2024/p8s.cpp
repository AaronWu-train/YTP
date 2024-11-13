#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ff first
#define ss second
vector<int> used(500007,0);
int prim(vector< vector<pii> >& graph, int ori,int o2) {
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    vector<int> currentMinCost(graph.size(), INT32_MAX);
    vector<bool> inside(graph.size(), false);
    int sum = 0;

    currentMinCost[ori] = 0;
	for(auto[w,v]:graph[ori]){
		if(v==o2){
			for(auto[x,u]:graph[o2]){
				currentMinCost[u]=x;
				pq.push({x,u});
				sum=w;
			}
		}else{
			currentMinCost[v]=w;
			pq.push({w,v});
		}
	}
	inside[ori]=1;
	inside[o2]=1;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (inside[u]) continue;
        inside[u] = true;
        sum += w;
        for (auto& [w, v]: graph[u]) {
            if (!inside[v] && currentMinCost[v] > w) {
                currentMinCost[v] = w;
                pq.push({w, v});
            }
        }
    }
    return sum;
}


signed main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    vector< vector<pii> > graph(vertexCount);
    int u, v, w;
	vector<pii> eg(edgeCount);
    for (int i = 0; i < edgeCount; i++) {
        cin >> u >> v >> w;u--;v--;
		eg[i]={u,v};
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});
    }
	for(int i=0; i<edgeCount; i++){
    	cout << prim(graph,eg[i].ff,eg[i].ss) << '\n';
	}
}

