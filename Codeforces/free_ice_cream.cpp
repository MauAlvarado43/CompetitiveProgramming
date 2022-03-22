#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int c, sad = 0;
    long long int q, s;

    cin >> q >> s;

    for(int i = 0; i < q; i++) {

        char t;
        cin >> t >> c;

        if(t == '+') {
            s += c;
        }
        else {
            if(c > s) {
                sad++;
            }   
            else {
                s -= c;
            }
        }

    }

    cout << s << " " << sad;

    return 0;

}