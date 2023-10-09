#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    int arr[n];
    int freq[n];
    for(int i = 0; i< n; i++) {
        cin>>arr[i];
        freq[i] = 0;
    }
    sort(arr, arr + n);
    int unique_val = 1;
    for(int i = 0; i<n-1; i++) {
        if (arr[i]==arr[i+1]) continue;
        else {
            unique_val += 1;
        }
    }
    cout<<unique_val;
    
}