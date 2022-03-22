#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool validate(vector<int>& queens, int i, int x) {

    for(int j = 0; j < i; j++) 
        if(queens[j] == x || abs(queens[j] - x) == abs(j - i)) 
            return false;
        
    return true;

}

void solve(vector<int>& queens, int i, int& count) {

    if(i < queens.size()) {

        for(int j = 0; j < queens.size(); j++) {
            if(validate(queens, i, j)) {
                queens[i] = j;
                solve(queens, i + 1, count);
            }
        }

    }
    else {

        count++;

        // for(int i = 0; i < queens.size(); i++) 
        //     cout << i << " -> " << queens[i] << endl;

        cout << "Solucion: " << count << "\n";

        for(int i = 0; i < queens.size(); i++) {

            for(int j = 0; j < queens.size(); j++) {

                if(queens[i] == j) 
                    cout << "1 ";
                else 
                    cout << "0 ";

            }

            cout << "\n";

        }

        cout << "\n";
        
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    int count = 0;

    if(n == 2 || n == 3) {
        cout << "Not possible\n";
        return 0;
    }

    vector<int> queens(n);
    solve(queens, 0, count);

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}