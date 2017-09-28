// @brief: Naive implementation of Binary Heap datastructure
// @note1: All counting uint, all indexing int
//
// @note2: This heap is implemented as 
//   - left min, 
//   - right max, 
//   - top max, 
//   - bottom min. aka maxheap

#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <cstring>
#include <cstdio>

namespace Heap 
{
using i32 = std::int32_t;
using u32 = std::uint32_t;
template<class Type> struct BinaryHeap;

namespace details 
{
    const u32 START_CAPACITY = 64;
    template<class Type, class Func> void upHeap(BinaryHeap<Type>& bh, const Func& compare);  
    template<class Type, class Func> void downHeap(BinaryHeap<Type>& bh, const Func& compare);
}

template<class Type>
struct BinaryHeap
{
    Type* items = new Type[details::START_CAPACITY];  // 0 - 63
    u32 count = 0;
    u32 capacity = details::START_CAPACITY;  // Grow to 128->256->512->1024.... osv
};


template<class Type, class Func>
void insert(BinaryHeap<Type>& bh, const Type& value, const Func& compare)
{
    if (bh.count < bh.capacity) 
    {
        bh.items[bh.count-1] = value;
        bh.count++;        
        details::upHeap(bh, compare);        
    }
    else 
        std::printf("Binary heap is full! ...");
}

template<class Type, class Func>
Type extract(BinaryHeap<Type>& bh, const Func& compare)
{   
    if (bh.count > 0) 
    {   
        Type retval = bh.items[0];
        bh.items[0] = bh.items[bh.count - 1];
        bh.count--;
        details::downHeap(bh, compare);        
        return retval;      
    }
    else 
    {
        std::printf("Binary heap is empty!...");
        return Type{};
    }
}

template<class Type>
const Type& peek(const BinaryHeap<Type>& bh) 
{
    if (bh.count > 0) 
        return bh.items[0];

    else 
    {
        std::printf("Binary heap is empty!...");
        return Type{};
    }
}

namespace details 
{
    inline const i32 getRightChildIndex(const i32 parent) 
    {
        return parent * 2 + 1;
    }
    inline const i32 getLeftChildIndex(const i32 parent) 
    {
        return parent * 2 + 2;    
    }
    inline const i32 getParentIndex(const i32 child) 
    {
        return (child + 1) / 2 - 1;
    }

    template<class Type, class Func>
    void upHeap(BinaryHeap<Type>& bh, const Func& compare) 
    {
        if (bh.count <= 1) return;      // Empty heap or only 1 node
        
        i32 itIndex = bh.count - 1; 
        i32 parentIndex = getParentIndex(itIndex);
        
        while (parentIndex >= 0) 
        {   
            if (compare(bh.items[itIndex], bh.items[parentIndex])) 
            {
                swap(bh, itIndex, parentIndex);
                itIndex = parentIndex;
                parentIndex = getParentIndex(itIndex);
            }
            else 
                break;
        }
    }

    template<class Type, class Func>
    void downHeap(BinaryHeap<Type>& bh, const Func& compare)
    {
        if (bh.count <= 1) return;      // Empty heap or only 1 node
        
        i32 itIndex = 0; 
        i32 leftChild = getLeftChildIndex(itIndex);     
        i32 rightChild = getRightChildIndex(itIndex);

    }

    template<class Type>
    void swap(BinaryHeap<Type>& bh, const i32 a, const i32 b) 
    {
        Type temp = bh.items[a];
        bh.items[a] = bh.items[b];
        bh.items[b] = temp;
    }

} // END OF namespace details
} // END OF namespace Heap