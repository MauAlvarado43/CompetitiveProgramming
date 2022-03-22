#include <bits/stdc++.h>
#define io_ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
    io_
    long long int k;
    long long int n; cin>>n>>k;
    long long int arr[n];
    long long int arrSums[n];
    long long int sum = 0;
    long long int indMin = LONG_MAX;

    for(long long int i = 0; i < n; i++) {
        cin>>arr[i];
        sum += arr[i];
        arrSums[i] = sum;
    }

    long long int l = 0, r = n;

    while(l <= r) {
        long long int m = (r-l)/2 + l;
        if(arrSums[m] == k) {
            l = m;
            r = m+1;
            break;
        } else if(arrSums[m] < k) {
            l = m+1;
        } else {
            r = m-1;
        }
    }

    long long int total = n - l;

    for(long long int i = 0; i < n; i++) {
        bool salir = false;
        while(!salir && l < n) {
            if(arrSums[l] - arrSums[i] == k) {
                total += n - l;
                salir = true;
            } else if(arrSums[l] - arrSums[i] > k) {
                l--;
                if(arrSums[l] - arrSums[i] < k) {
                    l++;
                    total += n - l;
                    salir = true;
                }
            } else {
                l++;
                if(l < n) {
                    if(arrSums[l] - arrSums[i] > k) {
                        total += n - l;
                        salir = true;
                    }
                }
            }
        }
    }

    if(total >= 0)
        cout<<total<<"\n";
    else
        cout<<0<<"\n";
    return 0;
}