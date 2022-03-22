#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int cases = 0;
    cin >> cases;

    for(int i = 0; i < cases; i++) {

        int n, min = 10000000, odd = 1;
        cin >> n;

        vector<int> ordered(n * 2);

        for(int j = 0; j < n; j++) {
            int temp;
            cin >> temp;
            ordered[temp] = j;
        }

        for(int j = 0; j < n; j++) {
            
            int b;
            cin >> b;

            while(odd < b) {

                if(min > ordered[odd] + j) 
                    min = ordered[odd] + j;

                odd += 2;
            }

        }

        cout << min << "\n";
            
    }

    return 0;

}