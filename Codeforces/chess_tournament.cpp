#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    int cases;
    cin >> cases;

    for(int k = 0; k < cases; k++) {

        int n;
        cin >> n;

        string players;
        cin >> players;

        string matrix[50][50];
        vector<int> win;

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++)
                matrix[i][j] = "=";

            matrix[i][i] = "X";

            if(players[i] == '2') 
                win.push_back(i);
            
        }

        if(win.size() == 1 || win.size() == 2) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for(int i = 0; i < win.size(); i++) {

            int j = win[(i + 1) % win.size()];

            matrix[win[i]][j] = "+";
            matrix[j][win[i]] = "-";
            
        }

        for(int i = 0; i < n; i++) {

            for(int j = 0; j < n; j++)
                cout << matrix[i][j];

            cout << "\n";
            
        }

    }

    return 0;

}