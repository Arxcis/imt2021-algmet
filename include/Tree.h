
// Node ...
struct Node
{
    char  key{};
    Node* left  = this; // for tree traversal
    Node* right = this; // for tree traversal
    Node* next  = this; // for stack traversal
};

// Stack ...
struct Stack
{
    Node* top = new Node{};
    Node* bottom = new Node{};
    Stack() { top->next = bottom; }
};

inline bool isEmpty(Stack* stack) {
    return stack->top->next == stack->bottom;
}

inline void push(Stack* stack, Node* node) {
    node->next = stack->top->next;
    stack->top->next = node;
}

inline Node* pop(Stack* stack) {
    Node* node = stack->top->next;
    stack->top->next = node->next;
    return node;
}
