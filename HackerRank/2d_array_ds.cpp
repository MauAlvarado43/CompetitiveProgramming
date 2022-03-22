#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int array[6][6];
    int maxSum = -INT32_MAX;

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            cin >> array[i][j];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {  

            int sum =   array[i][j] +     array[i][j + 1]     + array[i][j + 2] +
                                          array[i + 1][j + 1] + 
                        array[i + 2][j] + array[i + 2][j + 1] + array[i + 2][j + 2];

            if(sum > maxSum) maxSum = sum;

        } 
    }
    
    cout << maxSum << "\n";

    return 0;

}