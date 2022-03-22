Node * insert(Node * root, int data) {
        Node *pos = traeNodo(root,  data);
        Node *otroNodo = new Node(data);
        if (pos == NULL) {
            root = otroNodo;
        }else{
            if (data < pos->data) {
                pos->left = otroNodo;
            }else if(data > pos->data){
                pos->right = otroNodo;
            }
        }
        return root;
    }

    Node *traeNodo(Node *raiz, int dato){
        if(raiz == NULL){
            return NULL;
        }else if(raiz->left == NULL && raiz->right == NULL){
            return raiz;
        }else{
            if(dato < raiz->data ){
                if(raiz->left == NULL ){
                    return raiz;
                }else{
                    return traeNodo(raiz->left, dato);
                }
            }else if(dato > raiz->data ){
                if(raiz->right == NULL ){
                    return raiz;
                }else{
                    return traeNodo(raiz->right, dato);
                }
            }else{
                return raiz;
            }
        }
    }