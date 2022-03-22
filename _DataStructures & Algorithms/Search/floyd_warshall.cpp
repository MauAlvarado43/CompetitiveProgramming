#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m;
    cin >> n >> m;

    const int INF = 1e9;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<vector<int>> f(n, vector<int>(n, INF));

    for(int i = 0; i < n; i++)
        f[i][i] = 0;

    for(int i = 0; i < m; i++) {
        
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u][v] = w;
        f[u][v] = w;

    }

    for(int k = 0; k < n; k++) {
        for(int u = 0; u < n; u++) {
            for(int v = 0; v < n; v++) {
                f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
            }
        }
    }

    for(auto v: f) {
        for(auto x: v) 
            cout << x << " ";
        cout << "\n";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}