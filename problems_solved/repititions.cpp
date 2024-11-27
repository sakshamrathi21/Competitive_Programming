#include <iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string inputString;
    getline(cin, inputString);
    
    int count = 1;
    vector<int> vector_count;

    for(int i = 1; i<inputString.size()-1; i++){
        if(inputString[i] == inputString[i-1]) count ++;
        else {
            vector_count.push_back(count);
            count = 1;
        }
    }
    if(inputString.size() == 1) {
        cout<<1<<endl;
        exit(0);
    }
    if(inputString[inputString.size()-1] == inputString[inputString.size()-2]) {count += 1; vector_count.push_back(count);}
    int max = vector_count[0];
    for (int i = 1; i<vector_count.size(); i++) {
        if (max < vector_count[i]) max = vector_count[i];
    }
    cout<<max;
}