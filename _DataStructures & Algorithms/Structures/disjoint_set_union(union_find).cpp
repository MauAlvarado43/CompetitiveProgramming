#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

struct DSU {

    vector<int> parent;
    vector<int> rank;

    DSU(int n) : parent(n), rank(n) {
        for(int i = 0; i < n; i++) 
            parent[i] = i;
    }

    int find(int u) {
        return parent[u] =  (parent[u] == u ? u : find(parent[u]));
    }

    void set_union(int u, int v) {
        
        int pu = find(u);
        int pv = find(v);

        if(pv != pu) {

            if(rank[pu] < rank[pv])
                swap(pu, pv);
            
            if(rank[pu] == rank[pv])
                rank[pv]++;

            parent[pv] = pu;

        }

    }
    
    bool is_same_set(int u, int v) {
        return find(u) == find(v);
    }

};

// Path Compresion and size
struct UnionFind {

    vector<int> pa;
    vector<int> sz;
    // int numConj;

    UnionFind(int n) : pa(n), sz(n, 1) /*, numConj(n)*/ {
        for (int i = 0; i < n; i++) 
            pa[i] = i;
    }

    int find(int u) {
        return pa[u] = (u == pa[u] ? u : find(pa[u]));
    }

    bool unionSet(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if(sz[pu] < sz[pv])
            swap(pu, pv);

        if(pu != pv) {
            
            pa[pv] = pu;
            sz[pu] += sz[pv];
            // numConj--;

            return true;
        }

        return false;

    }

    bool isSameSet(int u, int v) {
        return find(u) == find(v);
    }

};

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<pair<int, int>> noSirven;
    UnionFind uf(n);

    for(int i = 0; i < n - 1; i++) {
        
        int u, v;
        cin >> u >> v;
        u--; v--;

        if(!uf.isSameSet(u, v))
            noSirven.push_back({u + 1, v + 1});

    }

    cout << noSirven.size() << "\n";

    int indx = 0;

    for(int i = 0; i < n; i++) {
        if(uf.isSameSet(0, i)) {
            cout << noSirven[indx].first << " " << noSirven[indx].second << " " << "1 " << (i + 1) << "\n";
            uf.unionSet(0, i);
            indx++;
        }
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}