#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    char s;
    cin >> s;

    if(s == '0') {
        cout << "0";
    }
    else {
        
        cout << "1";
        
        for(int i = 1; i < n; i++) {
            cin >> s;

            if(s == '0')
                cout << "0";
        }

    }

    return 0;

}