#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

bool bs(vector<int>& a, int t, int l, int r) {

    if(l > r) return false;

    int m = (r - l) / 2 + l;

    if(a[m] == t) 
        return true;

    else if(a[m] > t) 
        return bs(a, t, l, m - 1);
        
    else if(a[m] < t) 
        return bs(a, t, m + 1, r);

}

int lower_bound(vector<int>& a, int t, int l, int r) {

    if(l > r) return l;

    int m = (r - l) / 2 + l;

    if(a[m] == t) 
        return bs(a, t, l, m - 1);

    else if(a[m] > t) 
        return bs(a, t, l, m - 1);
        
    else if(a[m] < t) 
        return bs(a, t, m + 1, r);

}

int upper_bound(vector<int>& a, int t, int l, int r) {

    if(l > r) return l;

    int m = (r - l) / 2 + l;

    if(a[m] == t) 
        return bs(a, t, m + 1, r);

    else if(a[m] > t)
        return bs(a, t, l, m - 1);

    else if(a[m] < t) 
        return bs(a, t, m + 1, r);

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