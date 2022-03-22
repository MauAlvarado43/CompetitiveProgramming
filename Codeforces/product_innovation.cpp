#include <bits/stdc++.h> 

using namespace std;

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    long long int n, p;
    cin >> n >> p;

    list<long long int> numbers(n);
    for(long long int& x : numbers) cin >> x;

    auto iterator = numbers.begin();
    advance(iterator, p - 1);

    long long int x;
    cin >> x;

    for(long long int i = 0; i < x; i++) {

        string s;
        cin >> s;

        if(s == "moveLeft") {
            if(iterator != numbers.begin())
                iterator--;
        }   
        else if(s == "moveRight") {
            if(iterator != prev(numbers.end(), 1))
                iterator++;
        }
        else if(s == "insertLeft") {
            long long int x;
            cin >> x;
            numbers.insert(iterator, x);
        }
        else if(s == "insertRight") {
            long long int x;
            cin >> x;
            numbers.insert(next(iterator, 1), x);
        }
        else {
            cout << *iterator << "\n";
        }

    }

    return 0;

}