#include<bits/stdc++.h>
using namespace std;

void print_all_gray_codes (int current_index, int maximum_index, int* bit_string) {
    if ( current_index == maximum_index - 1) {
        for (int i = 0 ; i < maximum_index ; i ++ ) {
            cout<<bit_string[i];
        }
        cout<<endl;
        if (bit_string[current_index] == 0) {
            bit_string[current_index] = 1;
        }
        else {
            bit_string[current_index] = 0;
        }
        for (int i = 0 ; i < maximum_index ; i ++ ) {
            cout<<bit_string[i];
        }
        cout<<endl;
        return;
    }
    print_all_gray_codes ( current_index + 1 , maximum_index , bit_string);

    if (bit_string[current_index] == 0) {
            bit_string[current_index] = 1;
    }
    else {
        bit_string[current_index] = 0;
    }

    print_all_gray_codes ( current_index + 1 , maximum_index , bit_string);

    return;
}

int main () {
    int n ;
    cin >> n;

    int bit_string[n];

    for (int i = 0 ; i < n ; i ++ ) {
        bit_string [i] = 0;
    }

    print_all_gray_codes (0, n, bit_string);
}