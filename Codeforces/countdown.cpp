#include <iostream>

using namespace std;

int main() {

    int cases = 0;
    cin >> cases;

    for(int i = 0; i < cases; i++) {

        int n, moves = 0;
        cin >> n;

        string number;
        cin >> number;

        for(int j = 0; j < n; j++) {

            if(number[j] != '0' && j != n - 1)
                moves++;

            moves += (number[j] - '0');

        }

        cout << moves << "\n";

    }

    return 0;

}