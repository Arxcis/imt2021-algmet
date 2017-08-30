
// Oppgavetekst 3-3 Implement a routine exchange(struct Node* t, struct Node* u) for a linked list that exchanges the positions of the nodes after the nodes pointer to by t and u.

#include <iostream>

struct Node {
    int key = 0;
    Node* next = this;
};

struct List {
    Node* head = new Node{};
    Node* z    = new Node{};

    List(){
        head->next = z;
    }
};

void printList(List* list) {
    Node* node = list->head->next;
    int i = 0;
    while (node != node->next) {
        std::cout << "Node key " << i++ << ": " << node->key << '\n';
        node = node->next;
    }
}

void exchange(Node* const t, Node* const u) {
    Node* const tNext     = t->next;
    Node* const tNextNext = t->next->next;
    Node* const uNext     = u->next;
    Node* const uNextNext = u->next->next;

    uNext->next = tNextNext;
    t->next     = uNext;

    tNext->next = uNextNext;
    u->next     = tNext;
}

void exchange__OPTIMIZED__(Node* const t, Node* const u) {
    Node* const tNext     = t->next;
    Node* const uNextNext = u->next->next;

    t->next = u->next;
    t->next->next = tNext->next;

    u->next       = tNext;
    u->next->next = uNextNext;
}

int main () {
    List mylist;
    // 1. Fill List with initial values
    {
        Node* temp = mylist.head;
        for (int i = 0; i < 10; i++) {
            Node* const newNode = new Node;
            newNode->key = i;

            newNode->next = mylist.z;
            temp->next = newNode;
            temp = newNode;
        }
    }

    // 2. Swap
    //exchange(mylist.head->next->next, mylist.head->next->next->next->next->next->next->next);
    exchange(mylist.head->next->next, mylist.head->next->next->next->next->next->next->next);

    // 4. Print values
    printList(&mylist);
    std::cout << "Hello....\n";
    return 0;
}
