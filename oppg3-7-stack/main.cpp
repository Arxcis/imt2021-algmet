
// Implement stack 3-7, same as oppgave 3-8 just not a queue

#include <iostream>
#include <cstring>
#include <iomanip>

struct Node  {
    char   key = 0;
    Node* next = this;
};

struct Stack {
    Node* head = new Node{};
    Node* z    = new Node{};
};

void display(Stack* stack) {
    Node* it = stack->head->next;
    std::cout << "Stack ||";

    while (it != it->next) {
       std::cout << it->key;
        it = it->next;
    }

    std::cout << "\n";
}

void push(Stack* stack, Node* node) {
    node->next = stack->head->next;
    stack->head->next = node;
}

Node* pop(Stack* stack) {
    Node* node = stack->head->next;
    stack->head->next = node->next;
    return node;
}

void runTestdata(Stack* const stack, const char* teststring) {

    for (int i = 0; i < strlen(teststring); ++i) {
        
        char value = teststring[i];

        if (value == '*') {
            pop(stack);
        }

        else if ((value >= 'A' && value <= 'Z') || (value >= 'a' && value <= 'z')) {
            Node* node = new Node{};
            node->key = value;
            push(stack, node);
        }   
        display(stack);  
    }
    std::cout << '\n';
}

int main () {
    // 1. Make stack
    Stack* stack = new Stack{};
    stack->head->next = stack->z;


    // 2. Run testdata string
    const char testdata[] = "EAS*Y**QUE***ST***I*ON**";
    runTestdata(stack, testdata);

    return 0;
}