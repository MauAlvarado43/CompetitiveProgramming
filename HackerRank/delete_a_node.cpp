#include <iostream>

using namespace std;

class Nodos{
    public:
        int elemento;
        Nodos* siguiente;

        Nodos(){
            elemento = 0;
            siguiente = nullptr;
        }

        Nodos(int dato){
            this->elemento = dato;
            siguiente = nullptr;
        }

};

class Listas{
    Nodos* iniLista;
    Nodos* finLista;

    public:
        Listas(){
            iniLista = nullptr;
            finLista = nullptr;
        }
        void insertarElelemento(int dato){
            Nodos* nodo = new Nodos(dato);
            //(*nodo).elemento = txt;
            if (iniLista == nullptr){
                iniLista = finLista = nodo;//inilista apunta a nodo
                //finLista = nodo;//finlista apunta a nodo
            }else{
                //obs cuando solo hay un elemento, inilista y finlista apuntan al mismo nodo
                //entonces al modificar uno se modifica el nodo
                //como el que cambia es el final, usamo ese
                finLista->siguiente = nodo;//el que estaba antes
                finLista = nodo; //lo cambio al nuevo  
            }
        }

        void printLista(){
            if (iniLista != nullptr){
                Nodos* nodoAux = new Nodos(0);
                nodoAux = iniLista;
                int ini = true;
                do{
                    cout<< nodoAux -> elemento<<" ";
                    nodoAux = nodoAux -> siguiente;
                }while (nodoAux != nullptr);
            }
        }
        void eliminar (int pos){
            Nodos * nodoAnt = new Nodos(0);
            Nodos * nodoElim = new Nodos(0);
            Nodos * nodoSig = new Nodos(0);
            if (pos != 0) {
                nodoAnt = iniLista;
                for (int i = 1; i < pos; i++) {
                    nodoAnt = nodoAnt->siguiente;
                }
            
                nodoElim = nodoAnt->siguiente;
                nodoSig = nodoElim->siguiente;
                nodoAnt->siguiente = nodoSig;
            }else{
                nodoElim = iniLista;
                nodoSig = nodoElim->siguiente;
                iniLista = nodoSig;
            }
        }

        
};

int main(){
    int n = 0, t;
    int txt = 0;
    Listas lista1 = Listas();
    cin>> t;
    while (t--){
        cin>>n;
        lista1.insertarElelemento(n);
    }
    cin>>t;
    lista1.eliminar(t);
    lista1.printLista();
    return 0;
}



