// #include <bits/stdc++.h>
// #include <chrono>

// #define ll long long int

// using namespace std;

// int main() {

//     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//     // auto start = chrono::high_resolution_clock::now();

//     int n, l, r;
//     cin >> n >> l >> r;;
    
//     map<char, int> m;
//     m.insert({'L', l - 1});
//     m.insert({'R', r - 1});

//     string s;
//     cin >> s;

//     int aux = 1;

//     int q;
//     cin >> q;

//     while(q--) {

//         char query;
//         cin >> query;

//         if(query == 'Q') {

//             char side;
//             cin >> side;

//             cout << s[m[side]];

//         }
//         else if(query == 'R') {

//             reverse(s.begin() + m['L'], s.begin() + m['R'] + 1);

//         }
//         else if(query == 'S') {

//             char side, moveTo;
//             cin >> side >> moveTo;

//             if(moveTo == 'L')
//                 m[side] -= aux;
//             else
//                 m[side] += aux;

//         }

//     }

//     // auto end = chrono::high_resolution_clock::now();
//     // double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
//     // time_taken *= 1e-9;
//     // cout << time_taken << setprecision(9) << "\n";

//     return 0;

// }

#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    deque<char> middle;
    stack<char> left;
    deque<char> right;

    bool inverted = false;

    int n, l, r;
    cin >> n >> l >> r;

    l--;
    r--;

    for(int i = 0; i < n; i++) {

        char c;
        cin >> c;

        if(i < l) {
            left.push(c);
        }
        else if(i >= l && i <= r) {
            middle.push_back(c);
        }
        else {
            right.push_back(c);
        }

    }

    int q;
    cin >> q;

    while(q--) {

        char query;
        cin >> query;
    
        if(query == 'Q') {

            char side;
            cin >> side;

            if(!inverted) {

                if(side == 'L') {
                    cout << middle.front();
                }
                else {
                    cout << middle.back();
                }

            }
            else {

                if(side == 'L') {
                    cout << middle.back();
                }
                else {
                    cout << middle.front();
                }
                
            }

        }
        else if(query == 'R') {
            inverted = !inverted;
        }
        else if(query == 'S') {

            char side, moveTo;
            cin >> side >> moveTo;

            if(!inverted) {

                if(side == 'L') {

                    if(moveTo == 'L') {

                        middle.push_front(left.top());
                        left.pop();

                    }
                    else {

                        left.push(middle.front());
                        middle.pop_front();

                    }

                }
                else {

                    if(moveTo == 'L') {

                        right.push_front(middle.back());
                        middle.pop_back();

                    }
                    else {

                        middle.push_back(right.front());
                        right.pop_front();

                    }

                }

            }
            else {

                if(side == 'L') {

                    if(moveTo == 'L') {

                        middle.push_back(left.top());
                        left.pop();

                    }
                    else {

                        left.push(middle.back());
                        middle.pop_back();

                    }

                }
                else {

                    if(moveTo == 'L') {

                        right.push_front(middle.front());
                        middle.pop_front();

                    }
                    else {

                        middle.push_front(right.front());
                        right.pop_front();

                    }

                }

            }

        }
    
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}