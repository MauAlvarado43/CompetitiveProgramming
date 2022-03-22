#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    map<string, int> owners;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        string name;
        cin >> name;

        if(owners[name] == 0) 
            cout << "NO\n";
        else
            cout << "YES\n";

        owners[name]++;

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}