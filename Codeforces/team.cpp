#include <iostream>

using namespace std;

int main() {

    int Petya, Vasya, Tonia;
    int n = 0;
    int problems = 0;

    cin >> n;

    for(int i = 0; i < n; i++) {

        cin >> Petya >> Vasya >> Tonia;

        if(Petya + Vasya + Tonia >= 2)
            problems++;

    }

    cout << problems;

    return 0;

}