#include<iostream>
using namespace std;

int main() {
    int n; 
    cin>>n;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int min_price = arr[0];
    int maximum_profit = 0;
    for (int i = 0 ; i < n; i++) {
        if (arr[i]<min_price) min_price = arr[i];
        else {
            maximum_profit = max(maximum_profit, arr[i] - min_price);
        }
    }
    cout<<maximum_profit;
}