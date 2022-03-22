void inOrder(Node * raiz) {
    if(raiz == nullptr) return;
    inOrder(raiz->left);
    cout<<raiz->data<<" ";
    inOrder(raiz->right);
}