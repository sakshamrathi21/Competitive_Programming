#include<iostream>
using namespace std;

long long return_number(long long y, long long x){
    if(y>x) {
        if (y %2 ==0) {
            return y*y - x + 1;
        }
        else {
            return (y-1)*(y-1) + x;
        }
    }
    else {
        if (x%2 == 1) {
            return x*x - y+1;
        }
        else {
            return (x-1)*(x-1) + y;
        }
    }
}

int main() {
    long long t; 
    cin>>t;

    long long y[t];
    long long x[t];

    for(long long i = 0; i<t; i++) {
        cin>>y[i]>>x[i];
    }

    for(long long i = 0; i<t; i++) {
        cout<<return_number(y[i], x[i])<<endl;
    }
}