#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> a(n);

    for(int& x : a) cin >> x;

    while(a.size() != 1) {

        int p = 0;

        for(int i = 0; i < a.size() && a.size() != 1; i++) {
            if(a[i] > a[p]) 
                p = i; 
        }

        if(a.size() != 1)
            a.erase(a.begin() + p);

        p = 0;

        for(int i = 0; i < a.size() && a.size() != 1; i++) {
            if(a[i] < a[p]) 
                p = i; 
        }

        if(a.size() != 1)
            a.erase(a.begin() + p);

    }

    cout << a[0];


    return 0;

}