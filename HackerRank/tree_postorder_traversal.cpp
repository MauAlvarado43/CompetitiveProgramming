void postOrder(Node * raiz) {
    if(raiz == nullptr) return;
    postOrder(raiz->left);
    postOrder(raiz->right);
    cout<<raiz->data<<" ";
}