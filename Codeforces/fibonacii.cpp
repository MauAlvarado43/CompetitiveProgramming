#include <iostream>

using namespace std;

int main() {

    int a = 1, b = 1;
    int n = 4;

    for (size_t i = 0; i < n; i++) {
        
        cout << a << endl;

        b = a + b;
        a = b - a;

    }   
    

    return 0;

}