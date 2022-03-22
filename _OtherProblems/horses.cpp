#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

vector<pair<int, int>> movements = {
    {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1},
    {2, -1}, {1, -2}
};

void printBoard(vector<vector<int>>& board) {

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\n";

}

bool verify(vector<vector<int>>& board) {
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == -1)
                return false;
        }
    }

    return true;

}

int solve(vector<vector<int>>& board, int it) {

    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(board[i][j] == it) {
                for(auto mov : movements) {
                    int x = i + mov.first;
                    int y = j + mov.second;
                    if(x >= 0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y] == -1) {
                        board[x][y] = it + 1;
                        solve(board, it + 1);
                        board[x][y] = -1;
                    }
                }
            }
        }
    }

    if(verify(board)) {
        printBoard(board);
        return true;
    }

    return false;

}

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n = 5;
    vector<vector<int>> board(n , vector<int>(n, -1));
    int x = 0, y = 0;
    board[x][y] = 1;

    solve(board, 1);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}