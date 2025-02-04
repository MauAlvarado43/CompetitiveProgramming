#include <bits/stdc++.h>

using namespace std;

long findMaxValue(vector<int> factor, vector<vector<int>> data, int x) {

    priority_queue<int> pq;
    long n = factor.size();

    for(long i = 0; i < n; i++) {
        
        priority_queue<long> curr_pq;

        for(long j = 0; j < data.size(); j++)
            curr_pq.push(data[j][i]);

        while(factor[i]--) {
            pq.push(curr_pq.top());
            curr_pq.pop();
        }

    }

    if(x > pq.size())
        return -1;

    long sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }

    return sum;

}

int main() {

    vector<int> factor = {2, 1, 3} ;
    vector<vector<int>> data = {{8, 4, 6}, {1, 2, 3}, {9, 5, 7}};
    int x = 2;

    cout << findMaxValue(factor, data, x) << endl;

    return 0;

}