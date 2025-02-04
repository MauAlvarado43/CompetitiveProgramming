#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int findMaximumScore(vector<int> stockPrices, int k) {

    unordered_map<int, vector<int>> f;
    for(int i = 0; i < stockPrices.size(); i++)
        f[stockPrices[i]].push_back(i);

    int ans = 1;

    for(auto e : f) {
        
        int n = e.second.size();
        vector<int> v = e.second;

        for(int i = 0; i < n - 1 ; i++) {

            int max_sum = 1;
            int temp_k = k;
            int m = i;

            for(int j = i + 1; j < n; j++) {
                
                int dist = v[j] - v[m] - 1;
                if(dist <= temp_k) {
                    max_sum++;
                    temp_k -= dist;
                    m = j;
                }
                else {
                    break;
                }

            }

            ans = max(ans, max_sum);

        }

    }

    if(stockPrices.size() != 0) return 1;
    return ans;

}

int main() {

    vector<int> stockPrices = {1, 1, 2, 1, 2, 1};
    int k = 3;

    cout << findMaximumScore(stockPrices, k) << endl;

    return 0;

}