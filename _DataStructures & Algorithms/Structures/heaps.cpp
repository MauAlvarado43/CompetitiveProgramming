#include <bits/stdc++.h>

using namespace std;

template <class T> class Heap {

    public:

        vector<T> array;

        void push(T data) {

            int i = array.size() - 1;
            array.push_back(data);
            
            while(i > 0) {
                if(array[i] > array[(i - 1) / 2]) {
                    swap(array[i], array[(i - 1) / 2]);
                    i = (i - 1) / 2;
                } 
                else {
                    i = 0;
                }
            }

        }

        void pop() {

            if(array.size() == 0) {
                cout<<"Empty heap\n";
                return;
            }

            int i = 0;
            swap(array[0], array[array.size() - 1]);
            array.pop_back();

            while((2 * i + 1) < array.size()) {
                if(array[i] < max(array[2 * i + 1], array[2 * i + 2])) {
                    if(array[2 * i + 1] >= array[2 * i + 2]) {
                        swap(array[i], array[2 * i + 1]);
                        i = 2 * i + 1;
                    } else {
                        swap(array[i], array[2 * i + 2]);
                        i = 2 * i + 2;
                    }
                } 
                else {
                    i = array.size();
                }
            }

        }

        T top() {
            return array[0];
        }

};


int main() {

    ios_base::sync_with_stdio(0);cin.tie(0);

    Heap<int> pqueue;

    pqueue.push(10);
    pqueue.push(5);
    pqueue.push(15);
    pqueue.push(20);

    cout<<pqueue.top()<<"\n";
    pqueue.pop();
    cout<<pqueue.top()<<"\n";
    
    priority_queue<int> heap;

    heap.push(10);
    heap.push(5);
    heap.push(15);
    heap.push(20);

    cout<<heap.top()<<"\n";
    heap.pop();
    cout<<heap.top()<<"\n";

    return 0;
}