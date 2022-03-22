#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int quit = 0;

    for(int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) quit++;
    }

    cout << quit;

    return 0;

}