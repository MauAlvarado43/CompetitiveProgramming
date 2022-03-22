// #include <bits/stdc++.h> 

// using namespace std;

// int main() {

//     ios_base::sync_with_stdio(0);cin.tie(0);

//     list<char> characters(100001);
//     char c;
//     int brackets = 0;
//     c = getchar();

//     while(c != EOF) {
        
//         if(c == '[') {
//             brackets++;
//         }  
//         else if(brackets != 0) {

//             vector<char> chars;

//             while(true) {

//                 if(c == ']') {
//                     brackets--;
//                     break;
//                 }
                    
//                 chars.push_back(c);
//                 c = getchar();

//             }

//             for(int i = chars.size() - 1; i >= 0; i--) {
//                 characters.push_front(chars[i]);
//             }

//         }
//         else {
//             characters.push_back(c);
//         }

//         c = getchar();

//     }

//     for(char c : characters) cout << c;

//     return 0;

// }

// #include <bits/stdc++.h> 

// using namespace std;

// int main() {

//     ios_base::sync_with_stdio(0);cin.tie(0);

//     vector<char> characters;
//     char c;
//     int brackets = 0;
//     c = getchar();

//     while(c != EOF) {
        
//         if(c == '[') {
//             brackets++;
//         }  
//         else if(brackets != 0) {

//             vector<char> chars;

//             while(true) {

//                 if(c == ']') {
//                     brackets--;
//                     break;
//                 }
                    
//                 chars.push_back(c);
//                 c = getchar();

//             }

//             for(int i = 0; i < chars.size(); i++) {
//                 cout << chars[i];
//             }

//         }
//         else {
//             characters.push_back(c);
//         }

//         c = getchar();

//     }

//     for(char c : characters) cout << c;

//     return 0;

// }

#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    string s;

    while(getline(cin, s)) {

        list<char> characters;
        list<char>::iterator aux(characters.begin());

        for(int i = 0; i < s.length(); i++) {

            if(s[i] == '[') {
                aux = characters.begin();
            }
            else if(s[i] == ']') {
                aux = characters.end();
            }
            else {
                characters.insert(aux, s[i]);
            }

        }

        for(char c : characters) 
            cout << c;

        cout << "\n";

    }

    return 0;

}