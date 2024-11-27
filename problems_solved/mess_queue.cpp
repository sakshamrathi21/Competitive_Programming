#include<iostream>
using namespace std;

template<typename T>
class node{
    public: 
        T data;
        node* next;
        node->next = NULL;
};

template<typename T>
class messQueue{
    public:
        T num_hostels;
        node<T>* head = new node<T>;
        head->data = 0;
        head->next = NULL;
        node<T>** tail = new node<T>*[num_hostels];
        
        void initialize() {
            head->data = 0;
            head->next = NULL;
            for(int i = 0; i<num_hostels; i++) {
                tail[i]->data = 0;
                tail->next = NULL;
            }
        }

        void enqueue(node* student) {
            if(head->data == 0) {
                head  = student;
                head->next = tail[head->data]; 
            }
            else {
                tail[student->data]->next = student;
                tail[student->data] = student;
            }
        }

        bool dequeue(node* container) {
            if()
        }


};

int main() {

}