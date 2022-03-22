#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

void reduceWall(vector<pair<ll, ll>>& wall, int test) {
    
    // cout << test << "\n";

    while(wall.size() >= 2) {

        if(wall[wall.size() - 2].first == wall.back().first) {
            wall[wall.size() - 2].second += wall.back().second;
            wall.pop_back();
        }
        else if(wall.back().second % 2 == 0 || wall[wall.size() - 2].second % 2 == 0) {

            if(wall[wall.size() - 2].first < wall.back().first) {
                
                if((wall.back().first - wall[wall.size() - 2].first) % 2 == 0) {
                    wall[wall.size() - 2].first = wall.back().first;
                }
                else {
                    wall[wall.size() - 2].first = wall.back().first + 1;
                }

            }

            wall[wall.size() - 2].second += wall.back().second;
            wall.pop_back();
        }
        else if((wall.back().first - wall[wall.size() - 2].first) % 2 == 0) {
            wall[wall.size() - 2].first = max(wall.back().first, wall[wall.size() - 2].first);
            wall[wall.size() - 2].second += wall.back().second;
            wall.pop_back();
        }
        else {
            break;
        }

    }

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    ll n, a;
    cin >> n; 

    vector<pair<ll, ll>> wall;

    for(int i = 0; i < n; i++) {

        cin >> a;
        
        if(wall.empty()) {
            wall.push_back(make_pair(a, 1));
        }
        else if(wall.back().first != a) {

            if(wall.back().second % 2 == 0) {

                if(wall.back().first < a) {
                    wall.back().first = a;                
                }
                else {
                    if((wall.back().first - a) % 2 == 0) {
                        wall.back().first = wall.back().first;
                    }
                    else {
                        wall.back().first++;
                    }
                }  

                wall.back().second++;

                reduceWall(wall, 1);

            }
            else {

                if((wall.back().first - a) % 2 == 0) {

                    wall.back().second++;

                    if(wall.back().second % 2 == 0) 
                        reduceWall(wall, 2);           
            
                }
                else {
                    wall.push_back(make_pair(a, 1));
                }
                
            }    

        }
        else {
            wall.back().second++;
        }

    }

    reduceWall(wall, 3);

    if(wall.size() == 1) 
        cout << "YES";
    else
        cout << "NO";

    // for(pair<ll, ll> x : wall) {
    //     cout << x.first << " " << x.second << endl;
    // }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}

// int main(){
//     int n,a,b=0;

//     cin>>n;

//     while(n--) {
//         cin >> a;
//         if((n ^ a) & 1)
//             b++;
//         else 
//             b--;
//     }

//     if(abs(b)<2)
//         cout<<"YES";
//     else 
//         cout<<"NO";

//     return 0;

// }