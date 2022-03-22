#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    io_
    int t = 0, n = 0, m = 0;
    int n1 = 0, n2 = 0;
    cin>>t;
    while (t--){
        cin>>n>>m;
        n = n-2;
        m = m-2;
        n1 = (int)(n/3);
        n2 = (int)(m/3);
        if(n % 3 != 0)
            n1++;
        if(m % 3 != 0)
            n2++;
        cout<< n1*n2 <<endl;
    }
}