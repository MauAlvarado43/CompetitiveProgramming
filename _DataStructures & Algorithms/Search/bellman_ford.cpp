#include <bits/stdc++.h>
#include <chrono>

#define ll long long int
#define ull unsigned long long int

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pis pair<int, string>

#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vi>
#define vpi vector<pii>
#define vvpi vector<vpi>

#define qi queue<int>

#define pqi priority_queue<int>
#define pqb priority_queue<int, vi, greater<int>>

using namespace std;

void bellman_ford(vector<tuple<int, int, ll>>& graph, int source, int n, int m) {

    vector<ll> dist(graph.size(), INT_MAX);
    dist[source] = 0;

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int u = get<0>(graph[j]);
            int v = get<1>(graph[j]);
            ll w = get<2>(graph[j]);

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // for(int i = 0; i < m; i++) {
    //     int u = get<0>(graph[i]);
    //     int v = get<1>(graph[i]);
    //     int w = get<2>(graph[i]);

    //     if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
    //         cout << "Negative cycle detected" << endl;
    //         return;
    //     }
    // }

    for(int i = 0; i < graph.size(); i++) {
        cout << dist[i] << " ";
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m, u, v, w;
    cin >> n >> m;

    vector<tuple<int, int, ll>> graph(n);
    vector<int> h(n, 0);

    for (int i = 0; i < m; i++) {

        cin >> u >> v >> w;
        u--; v--;

        graph.push_back(make_tuple(u, v, w));

    }

    bellman_ford(graph, 0, n, m);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}