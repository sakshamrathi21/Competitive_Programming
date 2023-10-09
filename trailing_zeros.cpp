#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int pow = 0;
    
    // Count the number of factors of 5 in n
    for (int i = 5; i <= n; i *= 5) {
        pow += n / i;
    }

    cout << pow;
}
