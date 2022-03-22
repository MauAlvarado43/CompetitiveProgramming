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

using namespace std;

struct edge {
    int to, weight, id;
};

bool dfs1(vector<vector<edge>> &graph, vi &visited, vi &path, int now, int destiny) {

    visited[now] = 1;

    if(now == destiny) 
        return true;

    for(auto &e : graph[now]) 
        if(!visited[e.to]) {
            if(dfs1(graph, visited, path, e.to, destiny)) {
                path.push_back(e.id);
                return true;
            }
        }

    return false;

}

bool dfs2(vector<vector<edge>> &graph, vi &visited, vi &path, vi &low, vi &disc, vi &bridges, int &time, int from,  int now, int destiny, int cut_id) {

    visited[now] = 1;
    disc[now] = low[now] = time++;

    bool aux = now == destiny;

    for(auto &e : graph[now]) {

        if(cut_id == e.id || e.id == from)
            continue;

        if(visited[e.to]) {
            low[now] = min(low[now], disc[e.to]);
        }
        else {

            bool found = dfs2(graph, visited, path, low, disc, bridges, time, e.id, e.to, destiny, cut_id);
            bridges[e.id] = low[e.to] == disc[e.to];

            low[now] = min(low[now], low[e.to]);

            if(found) {
                path.push_back(e.id);
                aux = true;
            }

        }

    }

    return aux;

}

void reset(vi &path, vi &visited, vi &bridges, int &timer) {

    path.clear();
    visited.assign(visited.size(), 0);
    bridges.assign(bridges.size(), 0);
    timer = 0;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;

    vector<vector<edge>> graph(n);
    vi visited(n, 0), bridges(m, 0), edge_cost(m, 0), low(m, 0), disc(m, 0), path1, path2, best;
    int time = 0, best_cost = INT_MAX;

    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;

        graph[x].push_back({y, w, i});
        graph[y].push_back({x, w, i});

        edge_cost[i] = w;
    }

    if(!dfs1(graph, visited, path1, s, t)) {
        cout << 0 << "\n" << 0 << "\n";
        return 0;
    }


    for(auto &id1 : path1) {

        reset(path2, visited, bridges, time);

        if(!dfs2(graph, visited, path2, low, disc, bridges, time, -1, s, t, id1)) {
            if(best_cost > edge_cost[id1]) {
                best_cost = edge_cost[id1];
                best = {id1};
            }
            continue;
        }
        
        for(auto &id2 : path2) {
            
            if(!bridges[id2])
                continue;

            if(best_cost > edge_cost[id1] + edge_cost[id2]) {
                best_cost = edge_cost[id1] + edge_cost[id2];
                best = {id1, id2};
            }

        }

    }

    if(best_cost == INT_MAX) {
        cout << -1 << "\n";
        return 0;
    }

    cout << best_cost << "\n";
    cout << best.size() << "\n";

    for(auto &u : best) {
        cout << u + 1 << " ";
    }

    cout << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}