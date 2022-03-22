#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> getPrimes(int n) {

    int sqrtN = (int) sqrt(n);
    vector<int> numbers;
    vector<int> primes;

    for(int i = 0; i < n + 1; i++)
        numbers.push_back(i);

    for(int i = 2; i <= sqrtN; i++)
        if(numbers[i] != -1)
            for(int j = i; j <= (n + 1) / i; j++)
                numbers[i * j] = -1;

    for(int i = 2; i < n + 1; i++)
        if(numbers[i] != -1)
            primes.push_back(numbers[i]);

    return primes;
    
}

vector<int> waiter(vector<int> number, int q) {
    
    vector<int> primes = getPrimes(10000);
    vector<int> A;
    stack<int> B;
    vector<int> answer;

    for(int i = 0; i < q; i++) {
        
        for(int j = number.size() - 1; j >= 0; j--) {
            
            if(number[j] % primes[i] == 0) 
                B.push(number[j]);
            else 
                A.push_back(number[j]);

        }

        while(!B.empty()) {
            // answer.push(B.top());
            answer.push_back(B.top());
            B.pop();
        }

        number.clear();

        for(int j = 0; j < A.size(); j++) 
            number.push_back(A[j]);
    
        A.clear();

    }

    for(int i = number.size() - 1; i >= 0; i--) 
        answer.push_back(number[i]);
    
    return answer;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
