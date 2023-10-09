#include<bits/stdc++.h>
using namespace std;

int parent(int i) {
    return ((i-1)/2);
}

int left(int i) {
    return (2*i+1);
}

int right(int i) {
    return (2*i+2);
}

void swap(vector<int> &heap, int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void insert_heap(vector<int> &heap, int entry) {
    int i = heap.size();
    //cout<<"HELLO"<<endl;
    //cout<<entry<<endl;
    heap.push_back(entry);
    //cout<<heap.size()<<endl;
    while (i > 0 && heap[parent(i)] > heap[i]) {
        swap(heap, i, parent(i));
        i = parent(i);
    }
}

int index_with_smallest_key(vector<int> &heap, int i, int j, int k) {
    if (heap[i] < heap[j]) {
        if (heap[k] < heap[i]) return k;
        else if (heap[k] > heap[j]) return i;
        else return i;
    }
    else {
        if (heap[k] < heap[j]) return k;
        else if (heap[k] > heap[i]) return j;
        else return j;
    }
}

void heapify(vector<int> &heap, int i) {
    // cout<<"HELLO "<<i<<endl;
    int c;
    if (left(i) >= heap.size()) return;
    if (right(i) >= heap.size()) {
        if (heap[i] < heap[left(i)]) c = i;
        else c = left(i);
    }
    else {
        c = index_with_smallest_key(heap, i, left(i), right(i));
    }
    if (c == i) return;
    swap(heap, c, i);
    heapify(heap, c);
}

int min_heap(vector<int> &heap) {
    return heap[0];
}

void delete_min (vector<int> &heap) {
    
    swap (heap, 0, heap.size()-1);
    
    heap.pop_back();
    
    heapify(heap, 0);
}

int main() {
    vector<int> heap;
    
    insert_heap(heap, 5);
    insert_heap(heap, 4);
    insert_heap(heap, 2);
    insert_heap(heap, 3);
    insert_heap(heap, 41);
    insert_heap(heap, 7);

    delete_min(heap);

    for (int i = 0; i < heap.size(); i++) {
        cout<<heap[i]<<endl;
    }
}