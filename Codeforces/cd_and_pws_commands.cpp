#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<string> routes;

    for(int i = 0; i < n; i++) {

        string command;
        cin >> command;

        if(command == "pwd") {

            for(string s : routes) 
                cout << "/" << s;

            cout << "/\n";
            
        }
        else {

            string arg;
            cin >> arg;

            string path = "";

            for(int j = 0; j < arg.size(); j++) {       

                if(arg[j] == '/' && j == 0)
                    routes.clear();
                else if(arg[j] == '/') {

                    if(path == "..") 
                        routes.pop_back();
                    
                    else 
                        routes.push_back(path);

                    path.clear();

                }
                else
                    path += arg[j];

            }

            if(path == "..") {
                routes.pop_back();
            }
            else {
                routes.push_back(path);
            }

        }

    }

    return 0;

}