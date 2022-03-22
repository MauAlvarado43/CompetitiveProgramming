#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, d;
    cin >> n >> d;    

    vector<int> arr(n);
    for(int& x : arr) cin >> x;

    for(int i = d; i < n; i++) cout << arr[i] << " ";
    for(int i = 0; i < d; i++) cout << arr[i] << " ";

    return 0;

}