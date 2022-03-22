#include <bits/stdc++.h> 

using namespace std;

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    int a = 0, b = 0;

    for(int i = 0; i < n; i++) {
        int j = i;
        a = 0, b = 0;
        for(j = i; j < n; j++) {

            if(s[j] == 'a') a++;
            else b++;

            if(a == b && i != j) {
                break;
            }

        }

        if(a == b) {
            cout << i + 1 << " " << j + 1 << "\n";
            break;
        }

    }

    if(a != b)
        cout << "-1 -1\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n = 0;
    cin >> n;

    while(n > 0) {
        solve();
        n--;
    }

    return 0;

}