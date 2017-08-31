
#include <iostream>
#include <cstring>
#include <cassert>

struct Node {
    char  key = 0;
    Node* next  = this; // For the stack
    Node* left  = this; // For the tree 
    Node* right = this; // For the tree 
};

struct Stack {
    Node* head = new Node{};
    Node* foot = new Node{};
    Stack() { head->next = foot; }
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

bool isEmpty(Stack* stack) {
    return stack->head->next == stack->foot;
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


Node* buildTree(const char* postfixstring) {
    Stack* const stack = new Stack{};

    for (size_t i = 0; i < strlen(postfixstring); ++i) {
        char c = postfixstring[i];

        if (c == '*' || c == '+') {
            Node* node = new Node{};
            node->key   = c;
            node->left  = pop(stack);
            node->right = pop(stack);
            push(stack, node);
        }
        else if ( c >= '0' && c <= '9') {
            Node* node = new Node{};
            node->key = c;
            push(stack, node);
        }
        else {
            std::cout << "Invalid character...\n";
            assert(1);
        }
        display(stack);
    }

    return stack->head->next;
}

void traverseTree(Node* root) {
    Stack* const stack = new Stack{};
    Node* t = nullptr;
    push(stack, root);
    std::cout << "FASIT.....\n";
    while(!isEmpty(stack)) {
        t = pop(stack);
        std::cout << t->key << '\n';
        
        if (t->left != t) 
            push(stack, t->left);
        if (t->right != t) 
            push(stack, t->right);
    }
}

int main () {    
    Node* root = buildTree("598+46**7+*");
    
    traverseTree(root);

    std::cout << "hehe\n";  
    return 0; 
}