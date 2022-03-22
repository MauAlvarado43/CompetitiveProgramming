#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, m;
    int s = 0;
    cin >> n >> m;

    vector<int> distances(n);
    vector<int> isZero;
    vector<vector<int>> vertexes(n);

    for(int i = 0; i < n; i++) {

        cin >> distances[i];

        if(distances[i] == 0) 
            isZero.push_back(i);

    }

    for(int i = 0; i < m; i++) {
        
        int u, v;
        cin >> u >> v;

        vertexes[u - 1].push_back(v - 1);
        vertexes[v - 1].push_back(u - 1);

    }

    for(int i = 0; i < isZero.size(); i++) {

        s = isZero[i];

        bool find = true;

        for(int j = 0; j < vertexes[isZero[i]].size(); j++) {

            if(distances[vertexes[isZero[i]][j]] != 1) {
                find = false;
                break;
            }

        }

        if(find) break;

    }

    cout << s + 1 << "\n";

    return 0;

}