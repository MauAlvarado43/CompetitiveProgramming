#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void recursive_bfs(vector<vector<int>>& adj, vector<int>& visited, queue<int>& q) {

    if(q.empty()) 
        return;

    int u = q.front();
    q.pop();

    cout << u + 1 << " ";

    for(int v : adj[u]) {
        if(!visited[v]) {
            q.push(v);
            visited[v] = 1;
        }
    }

    recursive_bfs(adj, visited, q);

}

void bfs(vector<vector<int>>& adj, int u) {

    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(u);

    visited[u] = 1;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        cout << u + 1 << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = 1;
            }
        }
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    int m;

    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> visited(n, 0);
    queue<int> q;

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }  

    bfs(adj, 0);

    // q.push(0);
    // visited[0] = 1;
    // recursive_bfs(adj, visited, q);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}