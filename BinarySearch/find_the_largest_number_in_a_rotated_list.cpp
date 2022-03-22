#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int solve(vector<int>& arr) {

    int l = 0;
    int r = arr.size() - 1;

    while(l <= r) {

        int m = (l + r) / 2;

        if(arr[m] < arr[0])
            r = m - 1;
        else
            l = m + 1;

    }

    return arr[r];
    
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}