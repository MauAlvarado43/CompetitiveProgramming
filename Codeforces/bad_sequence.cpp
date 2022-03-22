#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    string s;
    cin >> s;

    int aux = 0;
    bool isOk = true;

    for(int i = 0; i < n; i++) {

        if(s[i] == '(') {
            aux++;
        }
        else {
            aux--;

            if(aux < -1 ) {
                isOk = false;
                break;
            }

        }

    }

    if(isOk && aux == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;

}