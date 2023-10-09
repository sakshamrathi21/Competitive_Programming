#include<iostream>
using namespace std;

int m = 11;

int h_1(int k) {
    return (k%m);
}

int h_2(int k) {
    return (6 - k%6);
}

int double_hash(int k, int i) {
    return ((h_1(k) + i*h_2(k))%m);
}

void insert_hash_table(int* arr, int k) {
    int hashvalue = double_hash(k, 0);
    int i;
    for (i = 0; i<m; i++) {
        //cout<<hashvalue<<endl;
        if (arr[hashvalue] == 0) {arr[hashvalue] = k; 
        return;}
        hashvalue = double_hash(k, i+1);
    }
    if (i == m) {cout<<"Array Filled or element can't be filled.";
    return;}
}

int main() {
    int arr[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    insert_hash_table(arr, 41);
    insert_hash_table(arr, 22);
    insert_hash_table(arr, 44);
    insert_hash_table(arr, 59);
    insert_hash_table(arr, 32);
    insert_hash_table(arr, 31);
    insert_hash_table(arr, 74);
    for(int i =0 ; i<m; i++) {
        cout<<arr[i]<<" ";
    }
}