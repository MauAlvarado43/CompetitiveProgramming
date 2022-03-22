#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
    io_

    int n, k; cin>>n>>k;
    int arrFence[n];
    int arrSums[n];
    int sum = 0;
    int posMin = -1, sumMin;
    int l = 0;

    for(int i = 0; i < n; i++) {
        cin>>arrFence[i];
        sum += arrFence[i];
        arrSums[i] = sum;
    }

    sumMin = arrSums[k-1];
    posMin = 0;

    for(int i = k; i < n; i++) {
        if(arrSums[i] - arrSums[l] < sumMin) {
            sumMin = arrSums[i] - arrSums[l];
            posMin = l + 1;
        }
        l++;
    }

    cout<<posMin + 1<<"\n";

    return 0;
}