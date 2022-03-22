#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int dfsBR(int u, int p, vector<int>& low, vector<int>& disc, vector<vector<int>>& adj, vector<vector<int>>& br, int& Time) {

    low[u] = disc[u] = ++Time;

    for(int& v : adj[u]) {

        if(v == p) 
            continue;
                            
        if(!disc[v]) {
        
            dfsBR(v, u, low, disc, adj, br, Time); 

            if (disc[u] < low[v])
                br.push_back({u, v});

            low[u] = min(low[u], low[v]);

        } 
        else {
            low[u] = min(low[u], disc[v]);
        }

    }

}

void BR(vector<int>& low, vector<int>& disc, vector<vector<int>>& adj, vector<vector<int>>& br, int& Time) {

    low = disc = vector<int>(adj.size());
    Time = 0;

    for(int u = 0; u < adj.size(); u++)
        if(!disc[u])
            dfsBR(u, u, low, disc, adj, br, Time);

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