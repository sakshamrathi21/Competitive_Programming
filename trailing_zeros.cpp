#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int pow = 0;
    for (int i = 5; i <= n; i *= 5) pow += n / i;
    cout << pow;
}
