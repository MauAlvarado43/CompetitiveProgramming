#include <bits/stdc++.h> 

using namespace std;

void solve() {
    
    int n;
    cin >> n;

    int np = 0;
    int ni = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(x % 2== 0) np++;
        else ni++;

    }

    if(ni == 0) cout << "NO\n";
    else if(ni != 0 && np != 0) cout << "YES\n";
    else {
        if(n % 2 == 0) cout << "NO\n";
        else cout << "YES\n";
    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}