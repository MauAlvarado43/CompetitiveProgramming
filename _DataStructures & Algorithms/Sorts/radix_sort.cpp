#include <bits/stdc++.h>

using namespace std;

void countSort(vector<int>&arr, int n, int exp) {

    vector<int> output(n);
    vector<int> count(10, 0);
 
    for(int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for(int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for(int i = 0; i < n; i++)
        arr[i] = output[i];

}
 
void radixsort(vector<int>& arr) {

    int m = *max_element(arr.begin(), arr.end());
 
    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, arr.size(), exp);
    
}
 
int main() {

    vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
     
    radixsort(arr);

    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;

}