#include<iostream>
using namespace std;

class arrayStack {
    int N = 2;
    int* S = NULL;
    int h = -1;
    public:
        arrayStack() {
            S = (int*)malloc(sizeof(int)*N);
        }
        int size() {
            return h+1;
        }
        bool empty () {
            return h<0;
        }
        int top() {
            return S[h];
        }
        void push(int e) {
            if (size() == N) expand();
            S[++h] = e;
        }
        void pop() {
            if(!empty()) h--;
        }
    private:
        unsigned expand() {
            int new_size = N*2;
            int* tmp = (int*)malloc(sizeof(int)*new_size);
            for (unsigned i = 0; i<N; i++) {
                tmp[i] = S[i];
            }
            free(S);
            S = tmp;
            N = new_size;
        }
};