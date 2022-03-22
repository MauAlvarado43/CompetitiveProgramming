#include<bits/stdc++.h>

using namespace std;
  
void sortString(string &str) {

    int letters = 26;

    vector<int> char_array(letters);

    for(int i = 0; i < str.length(); i++)
        char_array[str[i] - 'a']++;   

    str.clear();

    for(int i = 0; i < letters; i++)
        for(int j = 0; j < char_array[i]; j++)
            str.push_back((char)(i + 'a'));

}
 
int main() {

    string s = "testcba";   
    sortString(s);   

    cout << s;

    return 0;

}