#include <bits/stdc++.h>
// #include <chrono>

#define ll long long int

using namespace std;

vector<int> getMinutes_Seconds() {
    vector<int> m;
    for (int i = 0; i < 60; i++)
        m.push_back(i);
    return m;
}

vector<int> getHours() {
    vector<int> hours;
    for (int i = 0; i < 24; i++)
        hours.push_back(i);
    return hours;
}

vector<int> getNumbers(string s) {

    vector<int> v;
    string temp = "";
    string temp2 = "";

    bool flag = false;

    for(int i = 0; i < s.length(); i++) {  

        if(s[i] == '-') {
            flag = true;
        }
        else if(s[i] == ',') {

            if(flag) {

                int start = stoi(temp);
                int end = stoi(temp2);

                for(int j = start; j <= end; j++)
                    v.push_back(j);
                
            }
            else {
                v.push_back(stoi(temp));
            }

            temp = "";
            temp2 = "";
            flag = false;

        }
        else {
            if(flag)
                temp2 += s[i];
            else
                temp += s[i];
        }

    }

    if(flag) {

        int start = stoi(temp);
        int end = stoi(temp2);

        for(int j = start; j <= end; j++)
            v.push_back(j);

    }
    else {
        v.push_back(stoi(temp));
    }

    return v;

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    bool matrix[24][60][60] = {false};
    int ocurr = 0, total = 0, n;    
    cin >> n;

    while(n--) {
        
        vector<int> hh, mm, ss;
        string h, m, s;
        cin >> h >> m >> s;

        if(h == "*")
            hh = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
        else 
            hh = getNumbers(h);

        if(m == "*")
            mm = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59};
        else 
            mm = getNumbers(m);

        if(s == "*")
            ss = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59};
        else 
            ss = getNumbers(s);

        total += hh.size() * mm.size() * ss.size();

        for(int i = 0; i < hh.size(); i++) {
            for(int j = 0; j < mm.size(); j++) {
                for(int k = 0; k < ss.size(); k++) {
                    if(matrix[hh[i]][mm[j]][ss[k]]) 
                        ocurr++;

                    matrix[hh[i]][mm[j]][ss[k]] = true;
                }
            }
        }

    }

    cout << total - ocurr << " " << total;

    // tareas ocurr

    // h, m, s

    // [0] [60] [60] = true
    // if(matrix)
    //     ocurr++;
    // tareas++;


    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}