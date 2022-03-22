#include <bits/stdc++.h>
using namespace std;
int fibonacci(int a) {
    if(a <= 1) {
       return a;
    } else {
        return fibonacci(a-1) + fibonacci(a-2);
    }
}
int main() {
    int n; cin>>n;
    cout<<fibonacci(n);
    return 0;
}