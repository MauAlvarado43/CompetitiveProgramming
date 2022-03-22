#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    map<string, int> system;
    
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        
        string aux;
        cin >> aux;

        if(system[aux] == 0) 
            cout << "OK\n";
        else 
            cout << aux << system[aux] << "\n";

        system[aux]++;

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}