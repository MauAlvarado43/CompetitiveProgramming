#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
    io_

    int n;cin>>n;
    int l0 = 0, l1 = 0, r0 = 0, r1 = 0;
    int t;

    for (int i = 0; i < n; i++) {
        int l, r; cin>>l>>r;
        if(l == 0)
            l0++;
        else
            l1++;

        if(r == 0)
            r0++;
        else
            r1++;
    }

    if(l0 > l1)
        t = l1;
    else
        t = l0;

    if(r0 > r1)
        t += r1;
    else
        t += r0;
    
    cout<<t<<"\n";
    return 0;
}