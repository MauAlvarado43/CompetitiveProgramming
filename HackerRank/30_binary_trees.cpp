#include <bits/stdc++.h>
#include <chrono>

#define ll long long int

using namespace std;

class Node {

    public:
        int data;
        Node *left, *right;
        Node(int data) {
            this->data = data;
            left = right = NULL;
        }

};

void _levelOrder(Node *root, vector<queue<int>>& values, int level) {

    if (root == NULL) return;

    values[level].push(root->data);
    
    _levelOrder(root->left, values, level + 1);
    _levelOrder(root->right, values, level + 1);

}

void levelOrder(Node *root) {

    vector<queue<int>> values(21, queue<int>());
    _levelOrder(root, values, 0);

    for(int i = 0; i < values.size(); i++) {
        while(!values[i].empty()) {
            cout << values[i].front() << " ";
            values[i].pop();
        }
    }

}

int main() {

    // ios_base::sync_with_stdio(0);cin.tie(0);
    //auto start = chrono::high_resolution_clock::now();

    Node *root = new Node(3);
    root -> left = new Node(2);
    root -> right = new Node(5);
    root -> left -> left = new Node(1);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(7);

    

    //auto end = chrono::high_resolution_clock::now();
    //double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    //time_taken *= 1e-9;
    //cout << time_taken << setprecision(9) << "\n";

    return 0;

}