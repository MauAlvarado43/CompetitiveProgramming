#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {

        int count = 0;

        string s;
        cin >> s;

        for(int j = 0; j < s.length() - 1; j++) {

            if(s[j] == s[j + 1]) 
                count++;

        }

        cout << count << "\n";

    }

    return 0;

}