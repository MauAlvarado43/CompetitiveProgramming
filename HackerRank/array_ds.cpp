#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    vector<int> array(n);

    for(int& x : array) cin >> x;

    for(int i = n - 1; i >= 0; i--) 
        cout << array[i] << " ";

    return 0;

}