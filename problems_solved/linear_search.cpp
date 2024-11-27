#include<iostream>
using namespace std;

int search( int* S, int n, int e) {
    for (int i = 0; i < n; i++) {
        if (S[i] == e) {
            return i;
        }
    }
    return -1;
}

int main(){
    int S[] = {1, 2, 4, 3, 6, 5, 9};
    int e = 3;
    cout << search(S, 7, e);
}