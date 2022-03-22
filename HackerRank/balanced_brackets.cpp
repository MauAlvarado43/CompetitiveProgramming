#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING expression as parameter.
 */

string isBalanced(string expression) {
    
    stack<int> syntax;
    
    for(int i = 0; i < expression.length(); i++) {
        
        if(expression[i] == '{')
            syntax.push(1);
        else if(expression[i] == '[')
            syntax.push(2);
        else if(expression[i] == '(')
            syntax.push(3);
        else if(expression[i] == ')') {
            if(syntax.empty() || syntax.top() != 3)
                return "NO";
            syntax.pop();
        }
        else if(expression[i] == ']') {
            if(syntax.empty() || syntax.top() != 2)
                return "NO";
            syntax.pop();
        }
        else if(expression[i] == '}') {
            if(syntax.empty() || syntax.top() != 1)
                return "NO";
            syntax.pop();
        }
            
    }
    
    if(syntax.empty())
        return "YES";
        
    return "NO";
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string expression;
        getline(cin, expression);

        string res = isBalanced(expression);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
