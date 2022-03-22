#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    map<string, string> nets;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string name, net;
        cin >> name >> net;
        nets[net] = name;
    }

    for(int i = 0; i < m; i++) {
        string action, net;
        cin >> action >> net;
        cout << action << " " << net << " #" << nets[net.substr(0, net.size() - 1)] << "\n";
    }

    // for(auto it = nets.begin(); it != nets.end(); it++) 
    //     cout << it -> second << " " << it -> first << endl;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}