#include<iostream>
using namespace std;

struct node {
    int data;
    node* next = NULL;
};

void print_linked_list(node* header) {
    node* iterator = header;
    while(iterator!=NULL) {
        cout<<iterator->data<<" ";
        iterator = iterator->next;
    }
    cout<<endl;
}

void insert_linked_list(int data, node* header) {
    node* tail = new node;
    tail->data = data;
    node* iterator = header;
    if (header->next == NULL){
        header->next = tail;
        return;
    } 
    while(iterator->next!=NULL) {
        iterator = iterator->next;
    }
    iterator->next = tail;
}

int find_middle_linked_list (node* header) {
    node* slow = header;
    node* fast = header;
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main() {
    node* header = new node;
    header->data = 6;
    insert_linked_list(5, header);
    insert_linked_list(6, header);
    insert_linked_list(7, header);
    insert_linked_list(8, header);
    insert_linked_list(9, header);
    insert_linked_list(0, header);
    insert_linked_list(2, header);
    //insert_linked_list(3, header);
    print_linked_list(header);
    cout<<find_middle_linked_list(header)<<endl;
}