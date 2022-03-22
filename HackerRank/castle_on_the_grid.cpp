#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    
    queue<pair<int, int>> nodes;
    vector<string> visited(grid.size(), string(grid[0].size(), 'F'));
    vector<vector<pair<int, int>>> paths(grid.size(), vector<pair<int, int>>(grid[0].size(), {-1, -1}));
    stack<pair<int, int>> shortestPath;

    nodes.push(make_pair(startX, startY));

    while(!nodes.empty()) {

        if(visited[goalX][goalY] == 'G')
            break;

        pair<int, int> current = nodes.front();
        nodes.pop();

        for(int j = current.second; j < grid.size(); j++) {
            
            if(grid[current.first][j] == 'X')
                break;

            if(visited[current.first][j] == 'F') {
                visited[current.first][j] = 'G';  
                paths[current.first][j] = {current.first, current.second};
                nodes.push(make_pair(current.first, j));
            }

        }

        for(int j = current.second; j >= 0; j--) {

            if(grid[current.first][j] == 'X')
                break;

            if(visited[current.first][j] == 'F') {
                visited[current.first][j] = 'G';  
                paths[current.first][j] = {current.first, current.second};
                nodes.push(make_pair(current.first, j));
            }

        }

        for(int i = current.first; i < grid.size(); i++) {

            if(grid[i][current.second] == 'X')
                break;
            
            if(visited[i][current.second] == 'F') {
                visited[i][current.second] = 'G'; 
                paths[i][current.second] = {current.first, current.second};
                nodes.push(make_pair(i, current.second));
            }

        }          

        for(int i = current.first; i >= 0; i--) {

             if(grid[i][current.second] == 'X')
                break;
            
            if(visited[i][current.second] == 'F') {
                visited[i][current.second] = 'G'; 
                paths[i][current.second] = {current.first, current.second};
                nodes.push(make_pair(i, current.second));
            } 

        }

        visited[current.first][current.second] = 'V';

    }

    // for(int i = 0; i < visited.size(); i++) {
    //     for(int j = 0; j < visited[0].size(); j++) {
    //         cout << visited[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for(int i = 0; i < paths.size(); i++) {
    //     for(int j = 0; j < paths[0].size(); j++) {
    //         cout << "(" << paths[i][j].first << "," << paths[i][j].second << ") ";
    //     }
    //     cout << endl;
    // }

    pair<int, int> current = paths[goalX][goalY];

    while(current.first != startX || current.second != startY) {

        shortestPath.push(current);
        current = paths[current.first][current.second];

    }

    return shortestPath.size() + 1;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
