#pragma once
#include <iostream>

template <typename T>
class LinkedList_R {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& val) : value(val), next(nullptr) {}
    };

    Node* head_;
    Node* tail_;

public:
    LinkedList_R() : head_(nullptr), tail_(nullptr) {}

    void push_back(const T& val) {
        Node* new_node = new Node(val);

        if (head_ == nullptr) {
            head_ = tail_ = new_node;
        }
        else {
            tail_->next = new_node;
            tail_ = new_node;
        }
    }

    void print() const {
        Node* current = head_;

        while (current != nullptr) {
            std::cout << current->value;
            current = current->next;

            if (current != nullptr)
                std::cout << " -> ";
        }
        std::cout << std::endl;
    }

    // Prevent copying
    LinkedList_R(const LinkedList_R&) = delete;
    LinkedList_R& operator=(const LinkedList_R&) = delete;

    ~LinkedList_R() {
        Node* current = head_;

        // Clean up all nodes in the list
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};