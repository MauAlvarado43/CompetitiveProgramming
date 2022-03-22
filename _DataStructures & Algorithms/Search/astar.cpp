#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

struct Edge {
    int u, v, g;
    Edge(int u, int v, int g) : u(u), v(v), g(g) {}
};

void astar(vector<vector<Edge>>& graph, vector<int> h, int u, int v) {

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> f(graph.size(), INT_MAX);
    vector<int> path(graph.size(), -1);
    vector<bool> visited(graph.size(), false);

    pq.push({0, u});
    f[u] = 0;

    while(!pq.empty()) {

        pair<int, int> curr = pq.top();
        pq.pop();

        visited[curr.second] = true;

        for(auto next : graph[curr.second]) {
            if(!visited[next.v]) {

                int g_temp = next.g + curr.first;
                int f_temp = g_temp + h[next.v];

                if(f_temp < f[next.v]) {
                    f[next.v] = f_temp;
                    path[next.v] = curr.second;
                    pq.push({g_temp, next.v});
                }   

            }
        }    

    }

    cout << "Path: ";

    while(path[v] != -1) {
        cout << v + 1 << " ";
        v = path[v];
    }

    cout << v + 1 << endl;

}


int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m, u, v, w, a, b;
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    vector<int> h(n, 0);

    for (int i = 0; i < m; i++) {

        cin >> u >> v >> w;
        u--; v--;

        graph[u].push_back(Edge(u, v, w));
        graph[v].push_back(Edge(v, u, w));

    }

    for (int i = 0; i < n; i++) 
        cin >> h[i];
    
    cin >> a >> b;
    a--; b--;

    // for(auto g_ : g) {
    //     cout << g_ << " ";
    // }

    astar(graph, h, a, b);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}