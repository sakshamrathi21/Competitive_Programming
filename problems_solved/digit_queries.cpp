#include<bits/stdc++.h>
using namespace std;

long long int power(int n) {
    long long int result = 1;
    while (n > 0) {
        result *= 10;
        n--;
    }
    return result;
}
int find_digit ( long long int n ) {
    int current_length = 1;
    if ( n <= 9) return n;
    while ( n - current_length * power(current_length - 1) * 9 > 0 ) {
        n -= current_length * power(current_length - 1) * 9;
        current_length ++ ;
    }
    // cout<<"CHECK "<< current_length <<endl;
    long long int quotient = n / current_length;
    int remainder = n % current_length;
    
    long long int number_to_be_traversed;
    if (remainder == 0) {
        remainder = current_length;
        quotient --;
    }
    // cout << quotient << remainder << endl;
    if (current_length > 1) {
        number_to_be_traversed = power(current_length - 1) + quotient;
    }
    else {
        number_to_be_traversed = quotient;
    }
    // cout<<number_to_be_traversed << endl;
    
    while (number_to_be_traversed >= power(remainder)) {
        number_to_be_traversed /= 10;
    }
    return (number_to_be_traversed%10);
}

int main () {
    int num_test_cases;
    cin >> num_test_cases;

    for (int i = 0 ; i < num_test_cases; i ++ ) {
        long long int number_to_be_tested;
        cin >> number_to_be_tested;
        cout << find_digit ( number_to_be_tested ) << endl; 
    }

}