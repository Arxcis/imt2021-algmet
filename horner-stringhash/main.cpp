#include <iostream>
#include <cstring>
#include <stdint.h>

int64_t hash(const char str[]) {

    const int M = 991; // Prime number which is the size of the hash-table
    int64_t hash = 0;
    for ( ; *str; ++str) {
        hash = (64*hash + (*str)) % M;
    }

    return hash;
}

int main() {
    
    const int stringCount = 6;
    char strings[stringCount][20] = {
        "my",
        "name",
        "is",
        "jonas",
        "whatever",
        "youwanna_do",
    };

    for (int i = 0; i < stringCount; i++) {
        
        const char* str = strings[i];        
        std::cout << "Hash of " << str << ": " << hash(str) << "\n";
    }
    const char navn[] = "dettermittnavn";
    std::cout << navn << ": " << hash(navn) << "\n";
}