#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int matrix[5][5];

    int i0, j0;

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {

            cin >> matrix[i][j];
            if(matrix[i][j] == 1) {
                i0 = i;
                j0 = j;
            }

        }
    }

    cout << abs(2 - i0) + abs(2 - j0) << "\n";

    return 0;

}