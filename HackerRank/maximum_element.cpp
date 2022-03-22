#include <bits/stdc++.h>

#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    io_
    int t = 0;
    int op = 0;
    stack<int> lmin;
    cin>>t;
    while (t--){
        cin>> op;
        if(op == 1){
            int number;
            cin>> number;
            if(!lmin.empty()){
                lmin.push(max(number, lmin.top()));
            }else{
                lmin.push(number);
            }
        }else if(op == 3){
            if(!lmin.empty()){
                cout<<lmin.top() << "\n";
            }
        }else{//POP
            if(!lmin.empty()){
                lmin.pop();
            }       
        }
    }
    return 0;
}

