//
// Created by Bourne on 2017/12/28.
//

#ifndef ALGORITHMS_QUEUE_H
#define ALGORITHMS_QUEUE_H

#include <iostream>

class Node;

template <typename T>
class Queue
{
public:
    class Node {
    public:
        Node() : next_(nullptr) {}
        Node(T item) : item_(item), next_(nullptr) {}
        Node(T item, Node* next) : item_(item), next_(next) {}

        T item_;
        Node* next_;
    };

public:
    Queue() : first_(nullptr), last_(nullptr), size_(0) {}
    ~Queue()
    {
        while(first_ != nullptr) {
            Node* tmp = first_;
            first_ = first_->next_;
            delete(tmp);
        }

        first_ = last_ = nullptr;
        size_ = 0;
    }

    bool empty() const
    {
        return first_ == nullptr;
    }

    int size() const
    {
        return size_;
    }

    void enqueue(T item)
    {
        Node* tmp = last_;
        last_ = new Node(item, nullptr);
        if(empty()) {
            first_ = last_;
        } else {
            tmp->next_ = last_;
        }
        size_++;
    }

    T dequeue()
    {
        T item = first_->item_;
        first_ = first_->next_;

        if(empty()) {
            last_ = nullptr;
        }
        size_--;
        return item;
    }
private:
    Node* first_;
    Node* last_;
    int size_;
};

#endif //ALGORITHMS_QUEUE_H
