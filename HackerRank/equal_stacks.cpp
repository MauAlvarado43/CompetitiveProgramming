#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

void resta(int * alt, int *arr, int num) {
    *alt -= arr[num];
}

int main() {
    io_
    int n1, n2, n3, alt1 = 0, alt2 = 0, alt3 = 0, num1 = 0, num2 = 0, num3 = 0; cin>>n1>>n2>>n3;
    int pila1[n1], pila2[n2], pila3[n3];
    for(int i = 0; i < n1; i++) {
        cin>>pila1[i];
        alt1 += pila1[i];
    }
    for(int i = 0; i < n2; i++) {
        cin>>pila2[i];
        alt2 += pila2[i];
    }
    for(int i = 0; i < n3; i++) {
        cin>>pila3[i];
        alt3 += pila3[i];
    }
    while((alt1 != alt2) || (alt2 != alt3)) {
        if(alt1 >= alt2 && alt1 >= alt3){
            resta(&alt1, pila1, num1);
            num1++;
        } else if(alt2 >= alt1 && alt2 >= alt3) {
            resta(&alt2, pila2, num2);
            num2++;
        } else {
            resta(&alt3, pila3, num3);
            num3++;
        }
    }
    cout<<alt3<<"\n";
}