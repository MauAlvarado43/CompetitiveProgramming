#include <bits/stdc++.h> 

#define ll long long int

using namespace std;

template<typename T>

class Node {

    public:

        T value;
        Node<T> *next;

        Node(T x) {
            value = x;
            next = nullptr;
        }

};

template<typename T>

class Queue {

    Node<T> *start;
    Node<T> *end;
    size_t sz;

    public:

        Queue() {

            start = end = nullptr;
            sz = 0;
        
        }

        bool empty() {
            return start == nullptr;
        }

        void push(T value) {

            Node<T> *temp = new Node<T>(value);

            if(empty()) {
                start = end = temp;
            }
            else {
                end -> next = temp;
                end = temp;
            }

            sz++;

        }

        void pop() {

            if(empty()) {
                cout << "Queue is empty\n";
            }
            else if(start == end) {
                
                delete start;
                start = end = nullptr;
                sz--;
                
            }
            else {

                Node<T> *temp = start;
                start = temp -> next;
                delete temp;
                sz--;

            }

        }

        T front() {
            if(empty()) return NULL;
            return start -> value;
        }

        size_t size() {
            return sz;
        }

};

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    Queue<string> test;
    test.push("Club");
    test.push("Algoritmia");
    test.push("ESCOM");

    cout << test.front() << "\n";

    test.pop();

    return 0;

}