#include<iostream>
using namespace std;

int recursive_binary_search(int * S, int low, int high, int e) {
    int mid = (low + high) / 2;
    if (low >= high) return -1;
    else {
        if (S[mid] == e) return mid;
        else if (S[mid] > e) return recursive_binary_search(S, low, mid, e);
        else return recursive_binary_search(S, mid + 1, high, e);
    }
}

int main(){
    int S[] = {1, 2, 3, 4, 5, 6, 7, 9, 30};
    int e = 30;
    cout << recursive_binary_search(S, 0, 9, e);
}