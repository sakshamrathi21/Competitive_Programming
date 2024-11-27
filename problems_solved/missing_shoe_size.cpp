#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the initial number of pairs of shoes: ";
    cin>>n;
    int shoe_sizes[2*n-1];
    cout<<"Enter the shoe sizes: ";
    int missing_shoe_size = 0;
    for (int i = 0; i<2*n-1; i++) {
        cin>>shoe_sizes[i];
        missing_shoe_size ^= shoe_sizes[i];
    }
    cout<<"The missing shoe size is: "<<missing_shoe_size;
    

}