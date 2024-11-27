#include<iostream>
#include<vector>
using namespace std;

vector<int> permutation;

int n = 3;

bool chosen[3+1] = {0, 0, 0, 0};

void search() {
    if (permutation.size() == n) {
        cout<<"{ ";
        for(int i = 0; i<permutation.size(); i++) {
            cout<<permutation[i]<<", ";
        }
        cout<<"}"<<endl;
    }
    else{
        for(int i = 1; i<=n; i++) {
            if(chosen[i]) continue;
            chosen[i] = true;
            permutation.push_back(i);
            search();
            chosen[i] = false;
            permutation.pop_back();
        }
    }
}

int main(){
    search();
}