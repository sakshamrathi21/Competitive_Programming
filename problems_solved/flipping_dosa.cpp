#include<iostream>
#include<stack>
using namespace std;

class tava{
    int num_dosas;
    int* S = NULL;
    public:
        tava(int N) {
            S = (int*) malloc(sizeof(int)*N);
            num_dosas = N;
            for (int i = 0; i<num_dosas; i++){
                cin>>S[num_dosas-i-1];
            }
        }
        int size() {
            return num_dosas;
        }
        bool empty () {
            return num_dosas<=0;
        }
        int top() {
            sort();
            return S[num_dosas-1];
        }
    private:
        void sort() {
            int k = num_dosas-1;
            int min_index = num_dosas-1;
            for (k = num_dosas-2; k>=0; k--) {
                if (S[k] < S[min_index]) {
                    min_index = k;
                }
            }
            for (int i = min_index; i<(num_dosas-min_index)/2; i++) {
                int temp = S[min_index];
                S[min_index] = S[num_dosas-i-1];
                S[num_dosas-i-1] = temp;
            }

        }
};

int main() {
    int n;
    cin>>n;
    tava ram_dosa_stall(n);
    cout<<ram_dosa_stall.top();
    delete[] ram_dosa_stall.S;
}