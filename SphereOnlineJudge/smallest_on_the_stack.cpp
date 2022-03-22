#include <bits/stdc++.h>
#include <chrono>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main(){
    io_
    int t = 0;
    string op = "";
    
    stack<int> lmin;
    cin>>t;
    // auto start = chrono::high_resolution_clock::now();
    while (t--){
        cin>> op;
        if(op[1] == 'U'){
            int number;
            cin>> number;
            if(!lmin.empty()){
                lmin.push(min(number, lmin.top()));
            }else{
                lmin.push(number);
            }
        }else if(op[1] == 'I'){
            if(!lmin.empty()){
                cout<<lmin.top() << "\n\n";
            }else{
                cout<<"EMPTY\n\n";
            }
        }else{//POP
            if(!lmin.empty()){
                lmin.pop();
            }else{
                cout<< "EMPTY\n\n";
            }       
        }
    }
    return 0;
}

