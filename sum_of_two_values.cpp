#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, x;
    cin>>n>>x;
    long long arr[n];
    for(long long i = 0; i<n; i++) {
        cin>>arr[i];
    }
    long long sorted_arr[n];
    for(int i = 0; i<n; i++) {
        sorted_arr[i] = arr[i];
    }
    sort(sorted_arr, sorted_arr+n);
    long long i = 0, j = n-1;
    while(j>i) {
        if (sorted_arr[i]+sorted_arr[j] == x) {
            long long k = 0; 
            for(k = 0; k<n-1; k++) {
                if (arr[k] == sorted_arr[i]) break;
            }
            long long l = 0 ; 
            for(l = 0; l<n; l++) {
                if(l == k) continue;
                if(arr[l] == sorted_arr[j]) break;
            }
            if(k<l) cout<<k+1<<" "<<l+1;
            else cout<<l+1<<" "<<k+1;
            return 0;
        }
        else if(sorted_arr[i]+sorted_arr[j] < x) i++;
        else j--;
    } 
    cout<<"IMPOSSIBLE";
}