#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    int maxC = 0;
    int minC = INT32_MAX;
    int count = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if(i != 0) {

            if(x > maxC) 
                count++;
            else if(x < minC) 
                count ++;
            
        }

        maxC = max(x, maxC);
        minC = min(x, minC);

    }

    cout << count << "\n";

    return 0;

}