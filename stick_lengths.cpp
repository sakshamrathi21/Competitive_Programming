#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long arr[n];
    for(int i = 0;i<n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    long long median = arr[n/2];
    long long minimum_cost = 0;
    for(int i = 0; i<n; i++){
        minimum_cost += abs(arr[i]-median);
    }
    cout<<minimum_cost;
}