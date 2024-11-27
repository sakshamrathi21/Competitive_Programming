#include<bits/stdc++.h>
using namespace std;

int main() {
    int num_children;
    cin>>num_children;

    int maxweight;
    cin>>maxweight;

    int children_weights [num_children];

    for (int i = 0 ; i < num_children ; i ++) {
        cin>>children_weights[i];
    }

    sort(children_weights, children_weights+num_children);
    int low = 0; 
    int high = num_children-1;
    int num_baskets = 0;
    while(low<=high) {
        if (children_weights[high] > maxweight) break;
        if (children_weights[high] + children_weights[low] > maxweight) {
            high --;
            num_baskets ++;
        }
        else {
            low ++;
            high --;
            num_baskets ++;
        }
    }
    cout<<num_baskets;
}