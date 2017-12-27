//
// Created by Bourne on 2017/12/27.
//

#ifndef ALGORITHMS_LIST_H
#define ALGORITHMS_LIST_H

#include <iostream>

class Node;

template <typename T>
class List
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
    List() : first_(nullptr) {}
    ~List()
    {
        while(first_) {
            Node* tmp = first_;
            first_ = first_->next_;
            delete(tmp);
        }

        first_ = nullptr;
    }

    Node* push_front(T item)
    {
        Node* old_first = first_;
        first_ = new Node(item, old_first);
    }

    T pop_front()
    {
        if(first_ == nullptr) {
            std::cerr << "The list is null" << std::endl;
            exit(-1);
        }

        T result = first_->item_;
        first_ = first_->next_;

        return result;
    }

//    Node* push_back(T item);
//    T pop_back();

private:
    Node* first_;
};

//template <typename T>
//List<T>::Node * List<T>::push_front(T item)
//{
//    Node* old_first = first_;
//    first_ = new Node(item, old_first);
//}
//
//template <typename T>
//T List<T>::pop_front()
//{
//    if(first_ == nullptr) {
//        std::cerr << "The list is null" << std::endl;
//        exit(-1);
//    }
//
//    T result = first_->item_;
//    first_ = first_->next_;
//
//    return result;
//}

#endif //ALGORITHMS_LIST_H


