#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int array[n];
    for (int i = 0; i<n; i++) {
        cin>>array[i];
    }
    int count = 0;
    for (int i = 1; i<n; i++) {
        if(array[i]>=array[i-1]) continue;
        else{
            count-=array[i]-array[i-1];
            array[i] = array[i-1];
        }
    }
    cout<<count;
}