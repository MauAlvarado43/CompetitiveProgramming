#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;
    
    vector<string> words(n);

    for(string& word : words) cin >> word;
    for(string word : words) {

        if(word.length() > 10)
            cout << word[0] << word.length() - 2 << word[word.length() - 1] << "\n" ;
        else
            cout << word << "\n";
    }

    return 0;

}