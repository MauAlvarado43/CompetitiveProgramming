#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

const int mxn = 1e6;
vector<int> adj[mxn];
vector<vector<int>> adjList;
vector<int> tin, tout, flat, cost;
    
int n;
int Time = 0;

void dfs(int u, int pa) {

    tin[u] = Time;
    flat[Time] = cost[u];
    Time++;

    for(int v : adj[u])
        if(v != pa)
            dfs(v, u);

    tout[u] = Time - 1;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    cin >> n;
    adjList.resize(n);
    tin.resize(n);
    tout.resize(n);
    flat.resize(n);
    cost.resize(n);

    for(int i = 0; i < n; i++)
        cin >> cost[i];

    for(int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    dfs(0, -1);

    for(auto x : flat) 
        cout << x << " ";
    cout << endl;

    for(auto x : tin) 
        cout << x << " ";
    cout << endl;

    for(auto x : tout) 
        cout << x << " ";
    cout << endl;

    cout << endl;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}