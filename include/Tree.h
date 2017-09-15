namespace Tree 
{
    
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


inline bool empty(Stack* stack) 
{
    return stack->top->next == stack->bottom;
}

inline void push(Stack* stack, Node* node) 
{
    node->next = stack->top->next;
    stack->top->next = node;
}

inline Node* pop(Stack* stack) 
{
    Node* node = stack->top->next;
    stack->top->next = node->next;
    return node;
}


inline uint32_t countInternal(const Node* node) 
{
    uint32_t count     = 0;
    bool     countable = false;

    if (node->left != node) 
    {
        count += countInternal(node->left);
        countable = true;   
    }

    if (node->right != node) 
    {
        count += countInternal(node->right);
        countable = true;
    }

    if(countable)
        return 1 + count;
    return 0;
}


inline uint32_t countExternal(const Node* root) 
{
    uint32_t count     = 0;
    bool     countable = true;

    if (node->left != node) 
    {
        count += countExternal(node->left);
        countable = false;  
    }

    if (node->right != node) 
    {
        count += countExternal(node->right);
        countable = false;
    }

    if(!countable)
        return 0 + count;

    return 1;   
}

inline uint32_t countFull(const Node* node) 
{
    const uint8_t  LEFT  = 0b01;
    const uint8_t  RIGHT = 0b10;
    const uint8_t  FULL  = 0b11;

    uint32_t count = 0;
    uint8_t  state = 0b0;

    if (node->left != node) 
    {
        count += countFull(node->left);
        state |= LEFT;
    }

    if (node->right != node) 
    {
        count += countFull(node->right);
        state |= RIGHT;
    }

    if (state == FULL)
        return 1 + count;

    return 0;   
}

inline uint32_t height(const Node* node) 
{
    uint32_t heightLeft = 0;

    if (node->left != node)
        heightLeft = height(node->left);


    uint32_t heightRight = 0;

    if (node->right != node)
        heightRight = height(node->right);

    return (heightLeft > heightRight) ? heightLeft : heightRight;
}

inline bool number(char c) 
{ 
    return (c >= '0' && c <= '9'); 
}

inline bool letter(char c)
{
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

inline Node* MakePostfix(const char* postfixstring) {
    Stack* const stack = new Stack{};

    for (uint32_t i = 0; i < strlen(postfixstring); ++i) {
        char c = postfixstring[i];

        if (c == '*' || c == '+') {
            Node* node = new Node{};
            node->key = c;
            node->left  = pop(stack);
            node->right = pop(stack);
            push(stack, node);
        }
        else if (number(c)) {
            Node* node = new Node{};
            node->key = c;
            push(stack, node);
        }
        else {
            printf('There is something wrong with the postfixstring....\n');
            assert(0);
        }
    }
    return pop(stack); // @todo: check if stack has only 1 element
}

inline Node* MakePostfixCharacters(const char* postfixstring)
{
    Stack* stack = new Stack {};
    for (uint32_t i = 0; i < strlen(postfixstring); ++i) 
    {
        char c = postfixstring[i];
        if (letter(c))
        {   
            Node* const node = new Node{};
            node->key  = c;
            push(stack, node);    
        }
        else if (c == '*')
        {
            Node* const parent = pop(stack);
            parent->right = pop(stack);
            parent->left = pop(stack);
            push(stack, parent);
        }
        else if (c == '-')
        {
            Node* const parent = pop(stack);
            parent->left = left;
            push(stack, parent);
        }
        else if (c == '+') 
        {
            Node* const parent = pop(stack);
            parent->right = right;
            push(stack, parent);
        }
        else 
        {
            printf('There is something wrong with the postfixstring-modified....\n');
            assert(0);
        }
    }
    return pop(stack); // @todo: check if stack has only 1 element    
}

inline void traversePreorder(Node* root) 
{
    Stack* const stack = new Stack{};
    const Node* it = nullptr;

    push(stack, root);
    while(!isEmpty(stack)) {
        it = pop(stack);
        std::cout << t->key << '\n';
        
        if (it->right != it) 
            push(stack, it->right);
    
        if (it->left != it) 
            push(stack, it->left);
    }
}

// @todo incomplete BROKEN!!
inline void traverseInorder(Node* root)
{
    Stack* const stack = new Stack{};
    const Node* it = nullptr;

    push(stack, root);
    while(!isEmpty(stack)) { 

        if (it->left != it) 
            push(stack, it->left);
        
        if (it->right != it) 
            push(stack, it->right);
    }    
}

// @todo incomplete BROKEN!!
inline void traversPostorder(Node* root)
{
    Stack* const stack = new Stack{};
    const Node* it = nullptr;

    push(stack, root);
    while(!isEmpty(stack)) {
        it = pop(stack);
        std::cout << t->key << '\n';
        
        if (it->left != it) 
            push(stack, it->left);
        if (it->right != it) 
            push(stack, it->right);
    }    
}

} // end namespace tree