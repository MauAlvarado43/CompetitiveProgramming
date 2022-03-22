#include <bits/stdc++.h>

using namespace std;


typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    int t = 0;
    cin>>t;
    while (t--){
        string txt;
        cin>>txt;

        int contador[4] = {0, 0, 0, 0};
        int minn = INT_MAX;
        int r = 0, l = 0;

        while (l != txt.size()){
            while (r != txt.size() && l != txt.size()){
                if(contador[1] > 0 && contador[2] > 0 && contador[3] > 0){
                    minn = min(minn, r - l);
                    contador[txt[l] - '0']--;
                    l++;
                }else{
                    contador[txt[r] - '0']++;
                    r++;
                }
            }
            if(contador[1] > 0 && contador[2] > 0 && contador[3] > 0){
                minn = min(minn, r - l);
                contador[txt[l] - '0']--;
                l++;
            }else{
                break;
            }

        }

        if(contador[1] > 0 && contador[2] > 0 && contador[3] > 0){
            minn = min(minn, r - l);
            contador[txt[l] - '0']--;
            l++;
        }

        if(minn == INT_MAX)
            cout<< 0 <<"\n"; 
        else
            cout<< minn<<"\n"; 
    }


    return 0;

}