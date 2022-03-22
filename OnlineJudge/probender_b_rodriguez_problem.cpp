#include <bits/stdc++.h> 

using namespace std;

string getResult(string s1, string s2) {

    if(s1 == "+x") return s2;
    if(s1 == "-x") {
        string t = (s2[0] == '+') ? "-" : "+";
        t += s2[1];
        return t;
    }
    if(s1 == s2) return "-x";
    if(s1[1] == s2[1] && s1[0] != s2[0]) return "+x";
    if(s1[1] == 'y') return s1;
    if(s1[1] == 'z') return s1;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true) {

        string base = "+x";

        long long int n;
        cin >> n;

        if(n == 0) break;

        for(long long int i = 1; i < n; i++) {

            string bend;
            cin >> bend;

            if(bend == "No") continue;

            base = getResult(base, bend);

        }

        cout << base << "\n";

    }


    return 0;

}