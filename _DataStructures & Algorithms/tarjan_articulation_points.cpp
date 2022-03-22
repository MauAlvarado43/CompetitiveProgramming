#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int dfsAP(int u, int p, vector<int>& ap, vector<int>& low, vector<int>& disc, vector<vector<int>>& adj, int& Time) {

    int children = 0;
    low[u] = disc[u] = ++Time;
    
    for (int& v : adj[u]) {
        
        if(v == p)
            continue;
        
        if(!disc[v]) {

            children++;
            dfsAP(v, u, ap, low, disc, adj, Time);

            if (disc[u] <= low[v])
                ap[u] = 1;

            low[u] = min(low[u], low[v]); 

        } 
        else {
            low[u] = min(low[u], disc[v]);
        }

    }

    return children;

}

void AP(vector<int>& ap, vector<int>& low, vector<int>& disc, vector<vector<int>>& adj, int& Time) {

    ap = low = disc = vector<int>(adj.size());
    Time = 0;

    for(int u = 0; u < adj.size(); u++)
        if(!disc[u])
            ap[u] = dfsAP(u, u, ap, low, disc, adj, Time) > 1;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}