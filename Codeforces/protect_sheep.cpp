#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int r, c, w = 0;
    cin >> r >> c;

    vector<string> v(r, string(c, '.'));

    map<pair<int, int>, char> o;

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            
            char c;
            cin >> c;

            v[i][j] = c;

            if(c == 'S')
                o[{i, j}] = 'S';

            else if(c == 'W') {
                o[{i, j}] = 'W'; 
                w++;
            }  

        }
    }

    bool lose = false;

    for(auto it = o.begin(); it != o.end(); it++) {

        if(w == 0)
            break;
    
        if(it -> second == 'S') {

            auto aux = it -> first;

            if(o[{aux.first - 1, aux.second}] == 'W') {
                lose = true;
                break;
            }
            else if(o[{aux.first + 1, aux.second}] == 'W') {
                lose = true;
                break;
            }
            else if(o[{aux.first, aux.second - 1}] == 'W') {
                lose = true;
                break;
            }
            else if(o[{aux.first, aux.second + 1}] == 'W') {
                lose = true;
                break;
            }
            else {

                if(aux.first - 1 >= 0 && v[aux.first - 1][aux.second] == '.')
                    v[aux.first - 1][aux.second] = 'D';
                if(aux.first + 1 < r && v[aux.first + 1][aux.second] == '.')
                    v[aux.first + 1][aux.second] = 'D';
                if(aux.second - 1 >= 0 && v[aux.first][aux.second - 1] == '.')
                    v[aux.first][aux.second - 1] = 'D';
                if(aux.second + 1 < c && v[aux.first][aux.second + 1] == '.')
                    v[aux.first][aux.second + 1] = 'D';

            }

        }

    }

    if(lose)
        cout << "No\n";
    else {
        cout << "Yes\n";

        for(int i = 0; i < r; i++) {
            cout << v[i] << "\n";
        }

    }
    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}