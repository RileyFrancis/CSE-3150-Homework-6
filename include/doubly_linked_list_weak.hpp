#pragma once
#include <iostream>
#include <memory>

template <typename T>
class DoublyLinkedList_W {
private:
    struct Node {
        T value;
        std::shared_ptr<Node> next;
        std::weak_ptr<Node> prev;

        Node(T value) : value(value), next(nullptr), prev() {}

        ~Node() {
            std::cout << "Destroying node " << value << "\n";
        }
    };

    std::shared_ptr<Node> head_;
    std::shared_ptr<Node> tail_;

public:
    DoublyLinkedList_W() = default;
    ~DoublyLinkedList_W() = default;

    DoublyLinkedList_W(const DoublyLinkedList_W&) = delete;
    DoublyLinkedList_W& operator=(const DoublyLinkedList_W&) = delete;

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

    void print_backward() const {
        auto current = tail_;

        while (current != nullptr) {
            std::cout << current->value;

            auto prev = current->prev.lock();
            current = prev;

            if (current != nullptr)
                std::cout << " <- ";
        }
        std::cout << std::endl;
    }
};