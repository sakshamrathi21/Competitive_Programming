#include<iostream>
using namespace std;

int BinarySearch(int* S, int n, int e){
    int first = 0, last = n;
    int mid = (first + last) / 2;
    while (first < last){
        if (S[mid] == e) return mid;
        if (S[mid] > e) {
            last = mid;
        }
        else {
            first = mid + 1;
        }
        mid = (first + last) / 2;
    }
    return -1;
}

int main(){
    int S[] = {1, 2, 3, 4, 5, 6, 7, 9, 30};
    int e = 30;
    cout << BinarySearch(S, 9, e);
}