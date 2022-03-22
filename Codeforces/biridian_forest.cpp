#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int r, c;
    cin >> r >> c;

    int startX, startY, endX, endY;

    vector<vector<char>> grid(r, vector<char>(c));
    vector<vector<int>> distances(r, vector<int>(c, -1));

    for (int i = 0; i < r; i++) {

        for (int j = 0; j < c; j++) {
            
            cin >> grid[i][j];

            if(grid[i][j] == 'E') {
                startX = i;
                startY = j;
            }
            else if(grid[i][j] == 'S') {
                endX = i;
                endY = j;
            }

        }

    }

    queue<pair<int, int>> moves;
    moves.push({startX, startY});
    distances[startX][startY] = 0;

    while(moves.size()) {

        auto temp = moves.front();
        moves.pop();

        if(temp.first - 1 >= 0 && grid[temp.first][temp.second] && distances[temp.first - 1][temp.second] == -1 && grid[temp.first - 1][temp.second] != 'T') {
            moves.push({temp.first - 1, temp.second});
            distances[temp.first - 1][temp.second] = distances[temp.first][temp.second] + 1;
        }

        if(temp.first + 1 < r && grid[temp.first][temp.second] && distances[temp.first + 1][temp.second] == -1 && grid[temp.first + 1][temp.second] != 'T') {
            moves.push({temp.first + 1, temp.second});
            distances[temp.first + 1][temp.second] = distances[temp.first][temp.second] + 1;
        }

        if(temp.second - 1 >= 0 && grid[temp.first][temp.second] && distances[temp.first][temp.second - 1] == -1 && grid[temp.first][temp.second - 1] != 'T') {
            moves.push({temp.first, temp.second - 1});
            distances[temp.first][temp.second - 1] = distances[temp.first][temp.second] + 1;
        }

        if(temp.second + 1 < c && grid[temp.first][temp.second] && distances[temp.first][temp.second + 1] == -1 && grid[temp.first][temp.second + 1] != 'T') {
            moves.push({temp.first, temp.second + 1});
            distances[temp.first][temp.second + 1] = distances[temp.first][temp.second] + 1;
        }

    }

    int min_battles = 0;

    for(int i = 0; i < r; i++) 
        for(int j = 0; j < c; j++) 
            if(distances[i][j] != -1 && distances[i][j] <= distances[endX][endY] && grid[i][j] != 'S' && grid[i][j] != 'E')
                min_battles += grid[i][j] - '0';

    cout << min_battles << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}