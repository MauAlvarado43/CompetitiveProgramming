#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    string n ; cin>>n;
    ll suma = 0;
    for (char letra: n){
        suma += letra - '0';
    }
    ll res = suma%9;

    if(res == 0)
        cout<<"Yes\n";
    else
        cout<<"No";



    return 0;

}