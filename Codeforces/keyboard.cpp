#include <iostream>
#include <string>

using namespace std;

int main() {

    string s1 = "qwertyuiopasdfghjkl;zxcvbnm,./";
    string d;
    string s;
    cin >> d;
    cin >> s;

    for(int i = 0; i < s.length(); i++) {
        for(int j = 0; j < s1.length(); j++) {
            if(s[i] == s1[j]) {
                if(d == "R") {
                    cout << s1[(j - 1) % s1.length()];
                }
                else {
                    cout << s1[(j + 1) % s1.length()];
                }
                break;
            }
        }
    }

    return 0;

}