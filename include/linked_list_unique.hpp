#pragma once
#include <iostream>
#include <memory>

template <typename T>
class LinkedList_U {
private:
    struct Node {
        T value;
        std::unique_ptr<Node> next;
        Node(int value) : value(value), next(nullptr) {}
    };

    std::unique_ptr<Node> head_;
    Node* tail_;
    
public:
    LinkedList_U() : head_(nullptr), tail_(nullptr) {}
    ~LinkedList_U() = default;

    LinkedList_U(const LinkedList_U&) = delete;
    LinkedList_U& operator=(const LinkedList_U&) = delete;

    void push_back(T value) {
        auto node = std::make_unique<Node>(value);
        Node* raw = node.get();

        if (head_ == nullptr) {
            head_ = std::move(node);
            tail_ = raw;
        }
        else {
            tail_->next = std::move(node);
            tail_ = raw;
        }
    }
    void print() {
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