#include <bits/stdc++.h> 

using namespace std;

class Node {
    
    public:
        int x;
        Node *next;

    Node() {
        next = nullptr;
    }

};

class NodeList {

    public:
        Node *first;
        Node *last;

        void insertNode(int _x) {
            
            Node *node = new Node();
            node -> x = _x;

            if(first == nullptr) {
                first = last = node;
            }
            else {
                last -> next = node;
                last = node;
            }

        }

    NodeList() {
        last = first = nullptr;
    }

};

void solve(int t) {
    
    int n;
    cin >> n;

    NodeList *list = new NodeList();

    for(int i = 0; i < n; i++) {

        int x;
        cin >> x;

        list -> insertNode(x);

    }

    Node *node = list -> first;

    int _max = 0;

    while(node != nullptr) {
        _max = max(_max, node -> x);
        node = node -> next;
    }

    cout << "Case " << t << ": " << _max<< "\n";

}

int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        solve(i);
    }

    return 0;

}