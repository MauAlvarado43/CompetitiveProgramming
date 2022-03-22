#include <bits/stdc++.h> 

using namespace std;

vector<vector<char>> rotate(vector<vector<char>> matrix) {

    int n = matrix.size();
    vector<vector<char>> temp(n, vector<char>(n));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }

    return temp;

}

int findSquare(vector<vector<char>> squareN, vector<vector<char>> squaren) {

    int count = 0;

    for(int i = 0; i < squareN.size() - squaren.size() + 1; i++) {
        for(int j = 0; j < squareN.size() - squaren.size() + 1; j++) {

            bool find = true;   

            for(int m = 0; m < squaren.size(); m++) {

                for(int n = 0; n < squaren.size(); n++) {

                    if(squareN[i + m][j + n] != squaren[m][n]) {
                        find = false;
                        break;
                    }

                }

                if(!find) break;

            }

            if(find)
                count++;

        }
    }

    return count;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    while(true) {

        int n, N;
        cin >> N >> n;

        if(n == 0 || N == 0) break;

        vector<vector<char>> squareN(N, vector<char>(N));
        vector<vector<char>> squaren(n, vector<char>(n));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> squareN[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> squaren[i][j];
            }
        }

        int a = findSquare(squareN, squaren);
        int b = findSquare(squareN, rotate(squaren));
        int c = findSquare(squareN, rotate(rotate(squaren)));
        int d = findSquare(squareN, rotate(rotate(rotate(squaren))));

        cout << a << " " << b << " " << c << " " << d << "\n";

    }

    return 0;

}