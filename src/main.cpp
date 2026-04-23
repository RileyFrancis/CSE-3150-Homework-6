#include <iostream>
#include "linked_list_raw.hpp"
#include "linked_list_unique.hpp"
#include "doubly_linked_list_shared.hpp"
#include "doubly_linked_list_weak.hpp"


int main() {
    LinkedList_R<int> LLR;
    LLR.push_back(1);
    LLR.push_back(2);
    LLR.push_back(3);
    LLR.print();

    LinkedList_U<int> LLU;
    LLU.push_back(4);
    LLU.push_back(5);
    LLU.push_back(6);
    LLU.print();

    return 0;
}