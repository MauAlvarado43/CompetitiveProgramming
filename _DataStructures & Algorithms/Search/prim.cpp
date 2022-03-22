#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

struct DSU {

    vector<int> parent;
    vector<int> rank;

    DSU(int n) : parent(n), rank(n) {
        for(int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int find(int u) {
        return parent[u] =  (parent[u] == u ? u : find(parent[u]));
    }

    void unionSet(int u, int v) {
        
        int pu = find(u);
        int pv = find(v);

        if(pv != pu) {

            if(rank[pu] < rank[pv])
                swap(pu, pv);
            
            if(rank[pu] == rank[pv])
                rank[pv]++;

            parent[pv] = pu;

        }

    }
    
    bool sameSet(int u, int v) {
        return find(u) == find(v);
    }

};

struct Edge {

    int u, v, w;
  
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}

};

bool operator<(const Edge& a, const Edge& b) {
    return a.w > b.w;
}

struct Graph {

    vector<vector<Edge>> adj;
    vector<Edge> edges;
    int V;

    Graph(int n) : adj(n), V(n) {}

    void addEdge(int u, int v, int w) {
        assert(u < adj.size() && v < adj.size());
        adj[u].push_back(Edge(u, v, w));
        adj[v].push_back(Edge(v, u, w));
        edges.push_back({u, v, w});
    }

    void process(int u, priority_queue<Edge>& pq, vector<bool>& used) {
        used[u] = true;
        for(Edge& e : adj[u]) 
            if(!used[e.v])
                pq.push(e);
    }

    vector<Edge> prim() {

        priority_queue<Edge> pq;
        vector<bool> used(V);
        vector<Edge> mst;

        process(0, pq, used);

        while(!pq.empty()) {

            Edge e = pq.top();
            pq.pop();

            if(used[e.v])
                continue;

            mst.push_back(e);
            process(e.v, pq, used);

            if(mst.size() == V - 1)
                break;

        }

        return mst;

    }

};


int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    Graph g(n);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    cout << "\n";

    auto mst1 = g.prim();

    for(auto& x : mst1)
        cout << x.u << " " << x.v << " " << x.w << endl;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}