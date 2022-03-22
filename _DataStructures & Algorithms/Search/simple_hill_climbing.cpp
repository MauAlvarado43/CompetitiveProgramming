#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool simple_hill_climbing(vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& path, vector<int>& h, int u, int v) {

    if(u == v) 
        return true;

    if(visited[u])
        return false;

    visited[u] = true;

    for(auto w : adjList[u]) {
        if(h[w] <= h[u])
            if(simple_hill_climbing(adjList, visited, path, h, w, v)) {
                path.push_back(w);
                return true;
            }
    }

    return false;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<bool> visited(n, false);
    vector<int> path;
    vector<int> h(n, 0);

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }  

    for (int i = 0; i < n; i++) 
        cin >> h[i];

    cin >> a >> b;
    a--; b--;

    simple_hill_climbing(adj, visited, path, h, a, b);

    for(auto i : path)
        cout << i + 1 << " ";

    cout << a + 1 << endl;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}