#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& visited, int u) {

    cout << u + 1 << " ";

    visited[u] = 1;
    
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(adj, visited, v);
        }
    }

}

void iterative_dfs(vector<vector<int>>& adj, int u) {

    int n = adj.size();
    vector<int> visited(n, 0);
    stack<int> s;

    s.push(u);

    while (!s.empty()) {

        int u = s.top();
        s.pop();

        if (!visited[u]) {
            cout << u + 1 << " ";
            visited[u] = 1;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                s.push(v);
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> visited(n, 0);

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }  

    dfs(adj, visited, 0);
    // iterative_dfs(adj, 0);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}