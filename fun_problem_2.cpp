#include<iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int best_sum = 0; 
    int running_total = 0;
    for(int i = 0; i<n; i++) {
        running_total = max(arr[i], running_total + arr[i]);
        best_sum = max(best_sum, running_total);
    }
    cout<<best_sum;
}