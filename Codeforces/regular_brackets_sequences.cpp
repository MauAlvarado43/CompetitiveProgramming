// #include <bits/stdc++.h> 

// using namespace std;

// bool isFinalValid(string s) {
    
//     int carry = 0;

//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] == '(')
//             carry++;
//         else
//             carry--;
//     }

//     return carry == 0;

// }

// bool isValid(string s) {

//     int carry = 0;

//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] == '(')
//             carry++;
//         else
//             carry--;
        
//         if(carry < 0)
//             break;
//     }

//     return carry >= 0;

// }

// void bracketConcat(string s, int i, int n, int *c) {

//     if(!isValid(s))
//         return;

//     if((*c) == n / 2)
//         return;

//     if(isValid(s) && i == n) {

//         if(isFinalValid(s)) {
//             cout << s + "\n";
//             (*c)++;
//         }
            

//         return;
//     }

//     bracketConcat(s + "(", i + 1, n, c);
//     bracketConcat(s + ")", i + 1, n, c);

// }

// int main() {

//     ios_base::sync_with_stdio(0);cin.tie(0);

//     time_t start, end;
//     time(&start);

//     int t = 0;
//     cin >> t;

//     while(t > 0) {

//         int n = 0;
//         int c = 0;
        
//         cin >> n;
        
//         bracketConcat("", 0, 2 * n, &c);

//         t--;

//     }

//     time(&end);

//     cout << end - start;

//     return 0;

// }

#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int x = 0;
    cin >> x;

    while(x > 0) {

        string s;
        int n = 0;
        cin >> n;

        if(n == 2) {
            cout << "()()\n(())\n";
            x--;
            continue;
        }

        int n2 = 2 * n;

        for(int i = 0; i < n2; i++) {
            if(i < n)
                s += "(";
            else
                s += ")";
        }

        for(int i = n, j = n2 - 1, k = 0; k < n; i--, j--, k++) {
        
            cout << s << "\n";

            char t = s[i];
            s[i] = s[i - 1];
            s[i - 1] = t;

            t = s[j];
            s[j] = s[j - 1];
            s[j - 1] = t;

        }

        x--;

    }

    return 0;

}