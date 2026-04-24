#pragma once
#include <iostream>
#include <memory>

template <typename T>
class DoublyLinkedList_S {
private:
    struct Node {
        T value;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;
        Node(T value) : value(value), next(nullptr), prev(nullptr) {}
        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList_S() = default;
    ~DoublyLinkedList_S() = default;

    DoublyLinkedList_S(const DoublyLinkedList_S&) = delete;
    DoublyLinkedList_S& operator=(const DoublyLinkedList_S&) = delete;

    void push_back(T value) {
        auto node = std::make_shared<Node>(value);
        
        if (head_ == nullptr) {
            head_ = node;
            tail_ = node;
        }
        else {
            node->prev = tail_;
            tail_->next = node;
            tail_ = node;
        }
    }

    void print_forward() const {
        Node* current = head_.get();

        while (current != nullptr) {
            std::cout << current->value;
            current = current->next.get();

            if (current != nullptr)
                std::cout << " -> ";
        }
        std::cout << std::endl;
    }
};