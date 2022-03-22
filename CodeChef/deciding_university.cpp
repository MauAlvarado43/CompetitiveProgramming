#include <bits/stdc++.h>

#define ll long long int

#define vvpi vector<vector<pair<int, int>>>
#define vpi vector<pair<int, int>>
#define vvi vector<vector<int>>
#define vi vector<int>

#define pi pair<int, int>

using namespace std;

void bfs(vvi& graph, unordered_map<int, unordered_set<int>>& distances) {

    queue<pair<int, int>> q;
    vi visited(graph.size(), 0);
    visited[0] = 1;
    q.push({0, 0});

    while(!q.empty()) {

        int u = q.front().first;
        int d = q.front().second;
        q.pop();

        distances[d].insert(graph[u].size());

        for(int v : graph[u]) {
            if (!visited[v]) {
                q.push({v, d + 1});
                visited[v] = 1;
            }
        }

    }


}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;

    vvi cities(n);

    for(int i = 0; i < m; i++) {
        
        int u, v;
        cin >> u >> v;
        u--; v--;

        cities[u].push_back(v);
        cities[v].push_back(u);

    }

    unordered_map<int, unordered_set<int>> res;
    bfs(cities, res);

    for(int i = 0; i < q; i++) {

        int d, k;
        cin >> d >> k;
                 
        if(res.find(d) != res.end() && res[d].find(k) != res[d].end())
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;

}