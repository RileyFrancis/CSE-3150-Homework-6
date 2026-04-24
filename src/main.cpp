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

    LinkedList_R<char> LLR2;
    LLR2.push_back('a');
    LLR2.push_back('b');
    LLR2.push_back('c');
    LLR2.print();

    LinkedList_U<int> LLU;
    LLU.push_back(4);
    LLU.push_back(5);
    LLU.push_back(6);
    LLU.print();

    LinkedList_U<char> LLU2;
    LLU2.push_back('d');
    LLU2.push_back('e');
    LLU2.push_back('f');
    LLU2.print();

    // This is bad!
    {
        DoublyLinkedList_S<int> DLLS;
        DLLS.push_back(1);
        DLLS.push_back(2);
        DLLS.push_back(3);
        DLLS.print_forward();
    }

    std::cout << "I'm done!" << std::endl;

    DoublyLinkedList_W<int> DLLW;
    DLLW.push_back(1);
    DLLW.push_back(2);
    DLLW.push_back(3);
    DLLW.print_forward();

    return 0;
}