#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
int main() {
    io_
    int t;cin>>t;
    stack<int> pila;
    for(int i = 0; i < t; i++) {
        int q; cin>>q;
        if(q == 1) {
            int n; cin>>n;
            pila.push(n);
        } else if(q == 2) {
            if(!pila.empty())
                pila.pop();
        } else {
            if(!pila.empty())
                cout<<pila.top()<<"\n";
            else
                cout<<"Empty!\n";
        }
    }
}