#include <bits/stdc++.h>

using namespace std;
 
void shellSort(vector<int>& arr) {

    for(int gap = arr.size() / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < arr.size(); i++) {

            int temp = arr[i];
            int j = i; 

            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            arr[j] = temp;

        }
    }

}

int main() {

    vector<int> arr = {12, 32, 54, 2, 3};
 
    shellSort(arr);

    for(int x : arr)
        cout << x << " ";

    return 0;
    
}