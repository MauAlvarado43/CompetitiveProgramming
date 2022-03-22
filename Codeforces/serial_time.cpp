#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int k, n, m;
    cin >> k >> n >> m;

    vector<vector<string>> plate(k, vector<string>(n));
    vector<vector<vector<bool>>> visited(k, vector<vector<bool>>(n, vector<bool>(m, false)));

    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            cin >> plate[i][j];

    int x, y;
    cin >> x >> y;
    x--;
    y--;

    queue<vector<int>> q;
    q.push({0, x, y});
    visited[0][x][y] = true;

    while(!q.empty()) {

        auto temp = q.front();
        q.pop();

        int curr_z = temp[0];
        int curr_x = temp[1];
        int curr_y = temp[2];

        if(curr_x + 1 < n && plate[curr_z][curr_x + 1][curr_y] == '.' && !visited[curr_z][curr_x + 1][curr_y]) {
            q.push({curr_z, curr_x + 1, curr_y});
            visited[curr_z][curr_x + 1][curr_y] = true;
        }

        if(curr_x - 1 >= 0 && plate[curr_z][curr_x - 1][curr_y] == '.' && !visited[curr_z][curr_x - 1][curr_y]) {
            q.push({curr_z, curr_x - 1, curr_y});
            visited[curr_z][curr_x - 1][curr_y] = true;
        }

        if(curr_y + 1 < m && plate[curr_z][curr_x][curr_y + 1] == '.' && !visited[curr_z][curr_x][curr_y + 1]) {
            q.push({curr_z, curr_x, curr_y + 1});
            visited[curr_z][curr_x][curr_y + 1] = true;
        }

        if(curr_y - 1 >= 0 && plate[curr_z][curr_x][curr_y - 1] == '.' && !visited[curr_z][curr_x][curr_y - 1]) {
            q.push({curr_z, curr_x, curr_y - 1});
            visited[curr_z][curr_x][curr_y - 1] = true;
        }

        if(curr_z + 1 < k && plate[curr_z + 1][curr_x][curr_y] == '.' && !visited[curr_z + 1][curr_x][curr_y]) {
            q.push({curr_z + 1, curr_x, curr_y});
            visited[curr_z + 1][curr_x][curr_y] = true;
        }

        if(curr_z - 1 >= 0 && plate[curr_z - 1][curr_x][curr_y] == '.' && !visited[curr_z - 1][curr_x][curr_y]) {
            q.push({curr_z - 1, curr_x, curr_y});
            visited[curr_z - 1][curr_x][curr_y] = true;
        }

    }

    int t = 0;

    for(int i = 0; i < k; i++)
        for(int j = 0; j < n; j++)
            for(int z = 0; z < m; z++)
                if(visited[i][j][z] == 1)
                    t++;

    cout << t << endl;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}