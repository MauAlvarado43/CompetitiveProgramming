#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n;
    cin >> n;

    vector<int> a(n + 1);
    a.push_back(0);

    for(int i = 1; i <= n; i++) 
        cin >> a[i];

    bool cycle = false;

    for(int i = 1; i < n; i++)
        if(a[a[a[i]]] == i) {
            cycle = true;
            break;
        }

    if(cycle) 
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
    

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}