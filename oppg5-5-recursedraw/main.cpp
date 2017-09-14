#include <iostream>
#include <cstring>
#include <cassert>
#include "../include/Tree.h"

bool letter(const char c)
{
    return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}

// Defines a preorder tree traversal
Node* plantTree(const char* seed)
{
    Stack* stack   = new Stack{};

    for (size_t i = 0; i < strlen(seed); ++i)
    {
        const char c = seed[i];
        if (letter(c)) {
            push(stack, c);
        }
        else if (c == ')') {
            char right = pop(stack);
            char left  = pop(stack);
        }
    }
}

int main()
{
    // I DONT KNOW HOW TO REPRESENT A NORMAL BINARAY TREE HERE.....
    const char seed[] = "P(M(S(AA))L(E(R(TE)))";
    plantTree(seed);
    return 0;
}
