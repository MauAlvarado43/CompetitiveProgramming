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
class Stack {
    
  Node<T> *top;
  size_t sz;
  
  public:
  
    Stack() {
        top = nullptr;
        sz = 0;
    }
    
    bool empty() {
      // return sz == 0;
      return top == nullptr;
    }
    
    void push(T value) {
        Node<T> *temp = new Node<T>(value);
        temp -> next = top;
        top = temp;
        sz++;
    }
    
    void pop() {
        
        if(empty()) {
            cout << "Stack is empty\n";
            return;
        }
        
        Node<T> *temp = top;
        top = top -> next;
        delete temp;
        sz--;
        
    }
    
    T top_value() {
        
        if(empty()) return NULL;
        return top -> value;
        
    }
    
    size_t size() {
        return sz;
    }
    
};

int main() {
    
    Stack<string> s;
    
    s.push("1");
    s.push("2");
    s.push("3");
    
    cout << s.top_value() << "\n";
    s.pop();
    
    cout << s.top_value() << "\n";
    s.pop();
    
    cout << s.top_value() << "\n";
    
    return 0;
    
}