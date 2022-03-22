#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int count1s(int n) {

    int count = 0;

    if(n < 0) {
        // n = -n + 1;
        n = ~n;
        return 32 - count1s(n);
    }

    while(n) {
        count += n & 1;
        n >>= 1;
    }

    return count;

}

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while(t--) {
        
        int l, h;
        cin >> l >> h;

        int ans = 0;

        for(int i = l; i <= h; i++) 
            ans += count1s(i);

        cout << ans << "\n";

    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}


// #include <cmath>
// #include <cstdio>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;
      
        
// long long onesFromTo(long long a,long long b){// counts number of ones for a>=0 and b>=0 and a<=b
//     long long right = 0,count = 0,countedb = 0,counteda = 0,lastbitb = 0,lastbita = 0;
//     // I go through the bits of a and b from LSB to MSB by shifting the bits in every round to right
//     // counteda,countedb is what was already shifted away
//     // EXAMPLE: a=1011 couteda=0000 => a = 0101 counteda = 0001 => a = 0010 counteda = 0011 
//     // => a = 0001 counteda = 0011 => a = 0000 counteda = 1011
//     // right is a counter counting how many digits we shifted away
//     while(b!=0){
//         lastbitb = b&1;
//         lastbita = a&1;
//         //this computes the number of ones to be added to the sum when the next digit is added thus not being zero anymore.
//         //in the first loop iteration I compute the sum only for the last digit
//         //then I increase it step by step one digit at a time
//         count += 
//             // this part computes only if the new bit added is 1, else this is not needed since our number does not change
//             // the first term after multiplication is to produce the following sum: 
//             // (number of digits already added)*2^(number of digits already added)/2
//             // which gives us the number of 1's right of the current to get to 2^(right)-1 from 0
//             // so for right=3 it gives us number of 1s from 000 to 011
//             // now a 1 is added to get to 100
//             // and now I add what I already counted, since I want to 1AB, for AB as in the number was before, not to 100
//             lastbitb * ((right << max(0LL,right-1LL)) + 1LL + countedb)
//             // same here, but to substract the part from 0 to target number that we didn't need to walk, so this only is important if
//             // the current digit is not 0
//             - lastbita * ((right << max(0LL,right-1LL)) + counteda);
//         countedb += lastbitb<<right;
//         counteda += lastbita<<right;
//         right++;
//         a = a>>1;
//         b = b>>1;
//     }
//     return count;
// }
// long long onesFromToNeg(long long a,long long b){// counts number of ones for a,b<0 and a<=b
//     // I just move the problem to the positives
//     long long count = b-a+1LL;
//     a = a&~(1<<31); //remove sign
//     b = b&~(1<<31); //remove sign
//     count += onesFromTo(a,b);
//     return count;
// }

// long long ones(long long a, long long b){
//     if (a<0 && b<0)
//         return(onesFromToNeg(a,b));
//     else if (a<0 && b>=0)
//         return onesFromToNeg(a,-1)+onesFromTo(0,b);
//     else if (a>=0 && b>=0)
//         return onesFromTo(a,b);
//     else       
//         return 0;
// }

// int main() {
//     long long n;
//     cin >> n;
//     for(int i = 0; i< n;i++){
//         long long a,b;
//         cin >> a;
//         cin >> b;
//         cout<<ones(a,b)<<endl;
//     }
//     return 0;
// }
