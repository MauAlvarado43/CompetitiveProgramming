#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, t;
    cin >> n >> t;

    vector<int> booksTime(n + 1);
    
    booksTime[0] = 0;

    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        booksTime[i] = booksTime[i - 1] + x;
    }

    int aux = 0;
    int ans = 0;

    for(int i = 0; i <= n; i++) {

        if(booksTime[i] - booksTime[aux] > t) 
            aux++;
        else 
            ans = max(ans, i - aux);
            
    }

    cout << ans << "\n";

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}