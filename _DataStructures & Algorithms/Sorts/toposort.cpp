#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void dfs(int currentNode, vector<bool> &visited, vector<vector<int>> &adjList, vector<int> &ans) {

    if(visited[currentNode]) 
        return;

    visited[currentNode] = true;

    for(auto nextNode: adjList[currentNode]) 
        dfs(nextNode, visited, adjList, ans);

    ans.push_back(currentNode);
    
    return;

}

vector<int> toposort_dfs(vector<vector<int>> &adjList) {

    int n = adjList.size();
    vector<bool> visited(n);
    vector<int> ans;

    for(int i = 0; i < n; i++)
        if(!visited[i])
            dfs(i, visited, adjList, ans);

    reverse(ans.begin(), ans.end());

    return ans;

}

vector<int> toposort_bfs(vector<vector<int>> &adjList) {

    int cnt = 0;
    int n = adjList.size();
    vector<int> ans;
    vector<int> incoming_edges(n);
    queue<int> q;

    for(int i = 0; i < n; i++)
        for(auto v: adjList[i])
            incoming_edges[v]++;

    for(int i = 0; i < n; i++)
        if(incoming_edges[i] == 0) 
            q.push(i);        

    while(!q.empty()) {

        int u = q.front(); 
        q.pop();

        ans.push_back(u);
        cnt++;

        for(auto v: adjList[u]) {

            incoming_edges[v]--;

            if(incoming_edges[v] == 0)
                q.push(v);
            
        }

    }

    if(cnt != n) 
        return {-1};

    return ans;

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