#include<iostream>
#include<cmath>
using namespace std;

// long long knights_positions(int n) {
//     long long possibilities = 0;
//     for(int i = 0; i<n; i++) {
//         for (int j = 0; j<n; j++) {
//             long long total = n*n-1;
//             for (int k = 0; k<n; k++) {
//                 for (int l = 0; l<n; l++) {
//                     if (abs(i-k)==1 && abs(j-l) == 2) total --;
//                     if (abs(i-k)==2 && abs(j-l) == 1) total --;
//                 }
//             } 
//             possibilities += total;
//         }
//     }
//     return possibilities/2;
// }

long long count_ways(long long n) {
    //if (n ==5) return 252;
    if (n ==4) return 96;
    if (n == 3) return 28;
    if (n ==2) return 6;
    if (n == 1) return 0;
    return count_ways(n-1) + 3*(n*n-3) + 4*(n*n-4) + 2*(n-4)*(n*n-5) - (2*n-1)*(n-1) + 2;
}

int main() {
    long long n; 
    cin>>n;
    for(long long i = 1; i<= n; i++){
        cout<<count_ways(i)<<endl;
    }
}