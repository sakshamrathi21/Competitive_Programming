#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        freq[s[i] - 'A']++;
    }

    int oddCount = 0;
    int oddIndex = -1;

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
            oddCount++;
            oddIndex = i;
        }
    }

    if (oddCount > 1) {
        cout << "NO SOLUTION";
        exit(0);
    }

    string palindrome;

    if (oddCount == 1) {
        palindrome += static_cast<char>(oddIndex + 'A');
        freq[oddIndex]--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] % 2 != 0) {
            for (int k = 0; k < freq[i] / 2; k++) {
                palindrome += static_cast<char>(i + 'A');
            }
        }
    }

    string reversed = palindrome;
    reverse(reversed.begin(), reversed.end()); // Reverse the string

    palindrome += reversed;

    cout << palindrome << endl;

    return 0;
}
