#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void gbfs(vector<vector<int>>& adj, vector<int> h, int u, int v) {

    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> path(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({h[u], u});

    visited[u] = 1;

    while (!q.empty()) {

        pair<int, int> curr = q.top();
        q.pop();

        if(curr.second == v) 
            break;

        for (int v : adj[curr.second]) {
            if (!visited[v]) {
                q.push({h[v], v});
                visited[v] = 1;
                path[v] = curr.second;
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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> visited(n, 0);
    vector<int> h(n, 0);
    queue<int> q;

    for(int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }  

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    gbfs(adj, h, 0, 11);

    // q.push(0);
    // visited[0] = 1;
    // recursive_bfs(adj, visited, q);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}