#include <bits/stdc++.h>

using namespace std;
 
void bucketSort(vector<float>& arr) {
     
    int n = arr.size();
    int index = 0;
    vector<vector<float>> b(arr.size());
 
    for(int i = 0; i < n; i++) {
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
 
    for(int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
    
}
 
int main() {
    
    vector<float> arr = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };

    bucketSort(arr);
 
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
        
    return 0;

}