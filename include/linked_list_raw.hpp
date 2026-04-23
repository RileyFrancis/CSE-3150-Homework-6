#pragma once
#include <iostream>

template <typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void append(const T& val) {
        Node* new_node = new Node(val);

        if (head == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print() const {
        Node* current = head;

        while (current != nullptr) {
            std::cout << current->value;
            current = current->next;

            if (current != nullptr)
                std::cout << " -> ";
        }
        std::cout << std::endl;
    }

    // Prevent copying
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList&) = delete;

    ~LinkedList() {
        Node* current = head;
        
        // Clean up all nodes in the list
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};