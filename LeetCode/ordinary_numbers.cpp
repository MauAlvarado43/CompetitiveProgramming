#include <bits/stdc++.h> 

using namespace std;

long long int solve(string n) {

    string nextTo = "";
    long long int cn = stol(n, nullptr, 10);
    long long int count = n.length();

    if(cn < 10)
        return cn;

    for(int i = 0; i < count; i++)
        nextTo += n[0];

    if(stol(n, nullptr, 10) >= stol(nextTo, nullptr, 10))
        return (count * 9) - (9 - n[0] + '0');
    else
        return (count * 9) - 9 + (n[0] - '0' - 1);
        
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int n;
    cin >> n;

    while(n > 0) {

        string a;
        cin >> a;
        cout << solve(a) << "\n";

        n--;
    }

    return 0;

}