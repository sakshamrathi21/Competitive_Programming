#include<iostream>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long m;
    cin>>m;
    long long h[n];
    for(long long i = 0 ; i<n; i++) {
        cin>>h[i];
    }
    long long t[m];
    for(long long i = 0 ; i<m; i++) {
        cin>>t[i];
    }
    bool f[n];
    for(long long i = 0 ; i<n; i++) {
        f[i] = false;
    }
    for(int i = 0; i<m; i++) {
        int near_price = 0;
        int index = -1;
        for(int j = 0; j <n; j++) {
            if (near_price<h[j] && f[j] == false && t[i]>=h[j]) {
                near_price = h[j];
                index = j;
            }
        }
        if (index == -1) cout<<-1<<endl;
        else {
            cout<<near_price<<endl;
            f[index] = true;
        }
    }

}