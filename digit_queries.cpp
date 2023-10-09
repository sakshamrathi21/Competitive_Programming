#include<iostream>
#include<cmath>
using namespace std;

int digit_return(long long query_value) {
    int approx_n = 0;
    while (query_value > approx_n*pow(10, approx_n)-(pow(10, approx_n)-1)/9) {
        approx_n++;
        cout<<approx_n<<endl;
    }
    query_value -= (approx_n-1)*pow(10, approx_n-1)-(pow(10, approx_n-1)-1)/9;
    int remainder = query_value%approx_n;
    long long quotient = (query_value-remainder)/approx_n;
    cout<<remainder<<endl;
    long long real_number = pow(10, approx_n-1) + quotient - 1;
    if (remainder == 0) {
        return real_number % 10;
    }
    
    else {
        for (int i = 0; i<approx_n-remainder; i++) {
            real_number /= 10;
            cout<<real_number<<endl;
        }
        return real_number%10;
    }
}

int main() {
    int num_queries;
    cin>>num_queries;
    long long query_values[num_queries];
    for(int i = 0; i<num_queries; i++) {
        cin>>query_values[i];
    }
    for(int i = 0; i<num_queries; i++) {
        cout<<digit_return(query_values[i])<<endl;
    }

}