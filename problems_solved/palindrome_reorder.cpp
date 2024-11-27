#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    
    int freq[26] = {0};

    // for(int i = 0; i<26; i++) {
    //     freq[i] = 0;
    // }

    for(int i = 0; i<s.length(); i++) {
        freq[s[i]-65]++;
    }

    int oddCount = 0;

    int oddIndex = -1;

    for(int i = 0; i<26; i++) {
        if(freq[i]%2==1) {oddCount++;
        oddIndex = i;}
    }
    //cout<<oddCount<<endl<<oddIndex<<endl;
    if (oddCount>1) {cout<<"NO SOLUTION"; return 0;}

    int j = 0;

    if(oddCount == 1) {
        s[s.length()/2] =  static_cast<char>(oddIndex + 65);
    }

    freq[oddIndex] --;
    
    for (int i = 0; i<26; i++) {
         
            for(int k = 0; k<freq[i]/2; k++) {
                s[j] = static_cast<char>(i + 65);
                s[s.length()-j-1] = static_cast<char>(i + 65);
                j++;
        }
    }
    cout<<s;
}