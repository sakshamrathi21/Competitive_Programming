#include <iostream>
using namespace std;
typedef uintptr_t ut;

struct Node
{
    int data;
    struct Node *next;
    Node(int x) : data(x),
                  next(NULL) {}
};

void printData(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next != NULL)
            cout << " -> ";
        node = node->next;
    }
}

Node *reverse(Node *first)
{
    Node *curr = first;
    Node *prev = NULL;
    while (curr != NULL)
    {
    	// As discussed above.
        curr = (struct Node *)((ut)prev ^ (ut)curr ^ (ut)(curr->next) ^ (ut)(curr->next = prev) ^ (ut)(prev = curr));
    }
    return prev;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(53);
    head->next->next = new Node(13);
    head->next->next->next = new Node(43);
    head->next->next->next->next = new Node(52);


    cout << "Original Linked List: ", printData(head);
    head = reverse(head);
    cout << "\nReversed Linked List: ";
    printData(head);
    return 0;
}