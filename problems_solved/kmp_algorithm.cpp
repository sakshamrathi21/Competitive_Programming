#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> KMPTable(string P) {
    int i = 1;
    int j = 0; 
    vector<int> h(P.size()+1);
    h[0] = -1;
    while (i < P.size()) {
        if (P[i] != P[j]) {
            h[i] = j;
            while (j >= 0 && P[i] != P[j]) {
                j = h[j];
            }
        }
        else {
            h[i] = h[j];
        }
        i = i+1;
        j = j+1;
    }
    h[P.size()] = j;
    return h;
}

vector<int> KMP(string T, string P, vector<int> found) {
    int i = 0; 
    int j = 0; 
    vector<int>  h(P.size()+1);
    h = KMPTable(P);
    while (i <T.size()) {
        if (P[j] == T[i]) {
            i = i + 1;
            j = j + 1;
            if (j == P.size()) {
                found.push_back(i-j);
                j = h[j];
            }
        }
        else {
            j = h[j];
            if (j<0) {
                i++;
                j++;
            }
        }
    }
    return found;
}

int main() {
    string P = "babbaabba";
    string T = "xyzxyxxyxypx";
    for(int i = 0; i<= P.size(); i++) {
        cout<<KMPTable(P)[i]<<" ";
    }
}