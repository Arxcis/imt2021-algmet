// Oppgave 3-8 - Give the contents of the stack after each operation in the sequence æafsdkæadsløkfædsløkfæøsdalkfdsækflødsakføksd

#include <iostream>
#include <cstring>


struct Node {
    char   key  = 0;
    Node* next = this;
};

struct Queue {
    Node* const tail = new Node{};
    Node* const head = new Node{};
};

void put(Queue* queue, Node* node) {
    Node* it = queue->head;
    while (it->next != queue->tail) 
        it = it->next;

    node->next = queue->tail;
    it->next = node;
}

Node* get(Queue* queue) {
    Node* it = queue->head->next;
    queue->head->next = it->next;
    return it;
}

void display(Queue* queue) {
    Node* it = queue->head->next;
    int i = 0;
    while (it != it->next) {
        std::cout << it->key;
        it = it->next;
    }
    std::cout << '\n';
}

void runTestdata(Queue* const queue, const char* teststring) {
    
    for (int i = 0; i < strlen(teststring); ++i) {

        char value = teststring[i];

        if (value == '*') {
            
            // Get the first node in the queue
            Node* node = get(queue);
            display(queue);
        }

        else if ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')) {
            
            // Create and put node
            Node* node = new Node{};
            node->key = value;
            put(queue, node);
            display(queue);
        }     
    }
    std::cout << '\n';
}

int main () {
    // 1. Make queue
    Queue* queue = new Queue;
    queue->head->next = queue->tail;

    // 2. Run testdata string
    const char testdata[] = "EAS*Y**QUE***ST***I*ON**";
    runTestdata(queue, testdata);

    return 0;
}
