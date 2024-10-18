#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

struct enrrolment {
    set<int> requested;
    set<int> assigned;
};

enrrolment createEnrrolment() {
    enrrolment e;
    e.requested = set<int>();
    e.assigned = set<int>();
    return e;
}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    int n, m; cin >> n >> m;
    int mistakes = 0, not_requested = 0, missed = 0;

    map<int, enrrolment> students;

    for(int i = 0; i < n; i++) {

        int a, b; cin >> a >> b;
        students[a] = createEnrrolment();

        for(int j = 0; j < b; j++) {
            int bi; cin >> bi;
            students[a].requested.insert(bi);
        }

    }

    for(int i = 0; i < m; i++) {

        int a, c; cin >> a >> c;
        if(students.find(a) == students.end()) 
            students[a] = createEnrrolment();

        for(int j = 0; j < c; j++) {
            int ci; cin >> ci;
            students[a].assigned.insert(ci);
        }

    }

    for(auto it = students.begin(); it != students.end(); it++) {

        int student = it -> first;
        enrrolment e = it -> second;
        
        map<int, bool> actions; // true -> add, false -> remove

        for(auto it2 = e.assigned.begin(); it2 != e.assigned.end(); it2++) 
            if(e.requested.find(*it2) == e.requested.end())
                actions[*it2] = false;

        for(auto it2 = e.requested.begin(); it2 != e.requested.end(); it2++)
            if(e.assigned.find(*it2) == e.assigned.end())
                actions[*it2] = true;

        if(actions.size()) {

            mistakes++;
            cout << student;

            for(auto it2 = actions.begin(); it2 != actions.end(); it2++) {
                if(it2 -> second) { 
                    missed++;
                    cout << " +" << it2 -> first;
                }
                else {
                    not_requested++;
                    cout << " -" << it2 -> first;
                }
            }

            cout << "\n";

        }

    }

    if(mistakes == 0) {
        cout << "GREAT WORK! NO MISTAKES FOUND!";
    }
    else {
        cout << "MISTAKES IN " << mistakes << " STUDENTS: ";
        cout << not_requested << " NOT REQUESTED, " << missed << " MISSED";
    }

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}