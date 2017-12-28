//
// Created by Bourne on 2017/12/28.
//

#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include <iostream>

class Node;

template <typename T>
class Stack
{
public:
    class Node
    {
    public:
        Node() : next_(nullptr) {}
        Node(T item) : item_(item), next_(nullptr) {}
        Node(T item, Node* next) : item_(item), next_(next) {}

        T item_;
        Node* next_;
    };
public:
    Stack() : first_(nullptr), size_(0) {}
    ~Stack()
    {
        while(first_) {
            Node* tmp = first_;
            first_ = first_->next_;
            delete(tmp);
        }

        first_ = nullptr;
        size_ = 0;
    }

    bool empty()
    {
        return first_ == nullptr;
    }

    int size()
    {
        return size_;
    }

    void push(T item)
    {
        Node* tmp = first_;
        first_ = new Node(item, tmp);
        size_++;
    }

    T pop()
    {
        T item = first_->item_;
        first_ = first_->next_;
        size_--;
        return item;
    }

private:
    Node* first_;
    int size_;
};


#endif //ALGORITHMS_STACK_H
