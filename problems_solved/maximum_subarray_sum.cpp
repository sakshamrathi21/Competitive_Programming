#include<iostream>
using namespace std;
 

int main() {
    long long n;
    cin>>n;

    long long arr[n];
    for(long long i = 0; i<n; i++) {
        cin>>arr[i];
    }

    long long best_sum = -1*10e9; 
    long long running_total = 0;
    for(long long i = 0; i<n; i++) {
        running_total = max(arr[i], running_total + arr[i]);
        best_sum = max(best_sum, running_total);
    }

    cout<<best_sum;
}
