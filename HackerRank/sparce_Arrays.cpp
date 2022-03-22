#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    vector<string> strings(n);
    for(string& x : strings) cin >> x;

    int m;
    cin >> m;

    vector<string> queries(m);
    for(string& x : queries) cin >> x;

    for(int i = 0; i < m; i++) {
        
        int c = 0;

        for(int j = 0; j < n; j++) {
            if(queries[i] == strings[j])
                c++;
        }

        cout << c << "\n";
    }

    return 0;

}