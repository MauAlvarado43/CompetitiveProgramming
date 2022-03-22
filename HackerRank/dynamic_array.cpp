#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> array(n);
    int lastAnswer = 0;
    
    for(int i = 0; i < q; i++) {

        int query, x, y;
        cin >> query >> x >> y;

        int idx = (x ^ lastAnswer) % n;

        if(query == 1) {
            array[idx].push_back(y);
        }
        else {
            lastAnswer =  array[idx][y % array[idx].size()];
            cout << lastAnswer << "\n";
        }
        
    }

    return 0;

}