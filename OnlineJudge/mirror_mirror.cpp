#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int isEquals(vector<string> matrix1, vector<string> matrix2) {

    int count = 0;

    for(int i = 0; i < matrix1.size() - matrix2.size() + 1; i++) {
        for(int j = 0; j < matrix1.size() - matrix2.size() + 1; j++) {

            bool find = true;   

            for(int m = 0; m < matrix2.size(); m++) {

                for(int n = 0; n < matrix2.size(); n++) {

                    if(matrix1[i + m][j + n] != matrix2[m][n]) {
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

vector<string> flip(vector<string> matrix) {

    for(int i = 0; i < matrix.size() / 2; i++) {
        swap(matrix[i], matrix[matrix.size() - 1 - i]);
    }

}

vector<string> rotate(vector<string> matrix) {

    int n = matrix.size();
    vector<string> temp(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }

    return temp;

}

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    vector<string> matrix1;
    vector<string> matrix2;

    for(int i = 0; i < n; i++) {
        
        string s;
        cin >> s;
        matrix1.push_back(s);
        cin >> s;
        matrix2.push_back(s);

    }

    cout << "\n\n";

    for(int i = 0; i < n; i++) {
        cout << matrix1[i] << "\n";
    }

    cout << "\n\n";

    flip(matrix1);

    for(int i = 0; i < n; i++) {
        cout << matrix1[i] << "\n";
    }

    return 0;

}