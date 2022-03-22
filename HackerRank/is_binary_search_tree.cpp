vector<int> inOrderr;
void inOrder(Node* raiz){
    if(raiz == NULL)
        return;
    else{
        inOrder(raiz->left);
        inOrderr.push_back(raiz->data);
        inOrder(raiz->right);
    }
}

bool checkBST(Node* root) {
    inOrder(root);
    for(int i = 0; i < inOrderr.size() - 1; i++){
        if(inOrderr[i] >= inOrderr[i+1]){
            return false;
        }
    }
    return true;
}