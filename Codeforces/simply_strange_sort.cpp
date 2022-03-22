#include <bits/stdc++.h>

using namespace std;

void solve() {

    int n;
    cin >> n;

    vector<int> a(n);
    for(int& x : a) cin >> x;

    int count = 0;

    while(!is_sorted(a.begin(), a.end())) {
        
        for(int i = count % 2; i < n - 1; i += 2) {
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
            }
        }  

        count ++;
    }

    cout << count << "\n";

}

int main() {

    int n;
    cin >> n;

    while(n > 0){
        solve();
        n--;
    }

    return 0;

}