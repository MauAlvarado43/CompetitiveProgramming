#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> nodesQ(n);

    for(int i = 0; i < n; i++) 
        cin >> nodesQ[i];
    
    sort(nodesQ.begin(), nodesQ.end());

    ll sum = 0;

    for(int i = 0; i < n; i++)     
        sum = (sum * nodesQ[i]) + nodesQ[i];

    cout << sum + 1;

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}