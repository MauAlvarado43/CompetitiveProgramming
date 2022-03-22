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

void dijstra(vvpi& adjList, int src, int n) {

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vi dist(n, INT_MAX);
    vi parents(n, -1);

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {

        int v = pq.top().second;
        pq.pop();

        for(auto i : adjList[v]) {

            int u = i.first;
            int w = i.second;

            if(dist[u] > dist[v] + w) {
                parents[u] = v;
                dist[u] = dist[v] + w;
                pq.push({dist[u], u});
            }
        }
    }

    for(int i = 0; i < n ; i++)
        cout<<"Nodo: "<< i + 1 <<" Peso: "<< dist[i] << endl;
    

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m, u, v, w;
    cin >> n >> m;

    vvpi graph(n);
    vector<int> h(n, 0);

    for (int i = 0; i < m; i++) {

        cin >> u >> v >> w;
        u--; v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

    }

    dijstra(graph, 0, n);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}