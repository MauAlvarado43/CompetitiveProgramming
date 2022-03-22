#include <bits/stdc++.h>
#include <chrono>
 
#define ll long long int
 
using namespace std;
 
int main() {
 
    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();
 
    int n, k;
    cin >> n >> k;
 
    string walls[2];
    cin >> walls[0] >> walls[1];
 
    int visited[n][2];
    memset(visited, -1, sizeof(visited));
 
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;
 
    while(q.size()) {
 
        auto curr = q.front();
        int height = curr.first;
        int side = curr.second;
        int t = visited[height][side];
 
        q.pop();

        if(t > height)
            continue;

        if(height + 1 >= n || height + k >= n) {
            cout << "YES" << "\n";
            exit(0);
        }
 
        if(visited[height + 1][side] == -1 && walls[side][height + 1] == '-') {
            q.push({height + 1, side});
            visited[height + 1][side] = t + 1;
        }   
        
        if(height - 1 >= 0 && visited[height - 1][side] == -1 && walls[side][height - 1] == '-') {
            q.push({height - 1, side});
            visited[height - 1][side] = t + 1;
        }
 
        if(visited[height + k][!side] == -1 && walls[!side][height + k] == '-') {
            q.push({height + k, !side});
            visited[height + k][!side] = t + 1;
        }
 
    }
 
    cout << "NO" << "\n";
 
    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";
 
    return 0;
 
}