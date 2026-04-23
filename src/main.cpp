#include <iostream>
#include "linked_list_raw.hpp"
#include "linked_list_unique.hpp"
#include "doubly_linked_list_shared.hpp"
#include "doubly_linked_list_weak.hpp"


int main() {
    LinkedList<int> LLR;
    LLR.append(1);
    LLR.append(2);
    LLR.append(3);
    LLR.print();

    return 0;
}