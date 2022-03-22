#include <bits/stdc++.h>

using namespace std;
 
struct Node {
    int key;
    struct Node *left, *right;
};
 
struct Node* newNode(int item) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}
 
void inorder(struct Node* root) {
    if(root != NULL) {
        inorder(root -> left);
        cout << root -> key;
        inorder(root -> right);
    }
}
 
struct Node* insert(struct Node* node, int key) {

    if (node == NULL)
        return newNode(key);
 
    if (key < node -> key)
        node -> left = insert(node -> left, key);
    else
        node -> right = insert(node -> right, key);
 
    return node;

}
 
struct Node* minValueNode(struct Node* node) {
    
    struct Node* current = node;
 
    while (current && current -> left != NULL)
        current = current -> left;
 
    return current;

}

struct Node* search(struct Node* root, int key) {
    
    if (root == NULL || root -> key == key)
       return root;
    
    if (root -> key < key)
       return search(root -> right, key);
 
    return search(root->left, key);

}
 
struct Node* deleteNode(struct Node* root, int key) {

    if(root == NULL)
        return root;

    if(key < root -> key) {
        root -> left = deleteNode(root -> left, key);
    }
    else if(key > root -> key) {
        root -> right = deleteNode(root -> right, key);
    }
    else {

        if(root -> left==NULL && root -> right==NULL) {
            return NULL;
        }
        else if(root -> left == NULL) {
            struct Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL) {
            struct Node* temp = root -> left;
            free(root);
            return temp;
        }
 
        struct Node* temp = minValueNode(root -> right);
 
        root -> key = temp -> key;
        root -> right = deleteNode(root -> right, temp -> key);

    }

    return root;

}
 
int main() {

    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);
 
    cout << "Inorder traversal of the given tree \n";
    inorder(root);
 
    cout << "\nDelete 20\n";
    root = deleteNode(root, 20);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 30\n";
    root = deleteNode(root, 30);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    cout << "\nDelete 50\n";
    root = deleteNode(root, 50);
    cout << "Inorder traversal of the modified tree \n";
    inorder(root);
 
    return 0;

}