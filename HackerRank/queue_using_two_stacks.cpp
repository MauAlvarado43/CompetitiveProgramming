#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    stack<int> input;
    stack<int> output;

    for(int i = 0; i < n; i++) {

        int option;
        cin >> option;

        if(option == 1) {
            
            int aux;
            cin >> aux;

            input.push(aux);

        }
        else if(option == 2) {

            if(output.empty()) {

                while(!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }

            }
            
            output.pop();   

        }
        else if(option == 3) {

            if(output.empty()) {

                while(!input.empty()) {
                    output.push(input.top());
                    input.pop();
                }
            
            }

            cout << output.top() << "\n";

        }

    }

    return 0;

}