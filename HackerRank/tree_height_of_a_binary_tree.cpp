int height(Node * raiz) {

    int  alturaL = 0, alturaR = 0;

    if (raiz == NULL){
        return 0;
    }else if(raiz->left == NULL && raiz->right == NULL) {
        return 0;
    }else{
        return 1 + max( height(raiz->left), height(raiz->right));
    }
}