//
// Created by Bourne on 2017/12/26.
//

#ifndef ALGORITHMS_BINARYSEARCHTREE_H
#define ALGORITHMS_BINARYSEARCHTREE_H

#include <string>
using namespace std;

class BinarySearchTree
{
public:
    BinarySearchTree() : root_(nullptr) {

    }

    ~BinarySearchTree(){
        destroy(root_);
    }
    int size()
    {
        return size(root_);
    }

    string get(int key);
    void put(int key, string value);
    int min();
    int floor(int key);
    int max();
    int ceiling(int key);
    int select(int key);
    int rank(int key);

    void DeleteMin();
    void Delete(int key);
private:
    class Node {
    public:
        Node(int key, string value, int size) : key_(key), value_(value), size_(size), left_(nullptr), right_(nullptr)
        {

        }
    public:
        int key_;
        string value_;
        Node* left_;
        Node* right_;
        int size_;
    };

    Node* root_;

    int size(Node* root)
    {
        if(root == nullptr) {
            return 0;
        } else
            return root->size_;
    }

    string get(Node* root, int key);
    Node* put(Node* root, int key, string value);
    Node* min(Node* root);
    Node* floor(Node* root, int key);
    Node* max(Node* root);
    Node* ceiling(Node* root, int key);

    Node* select(Node* root, int key);
    int rank(Node* root, int key);

    Node* DeleteMin(Node* root);
    Node* Delete(Node* root, int key);

    void destroy(Node*& root);


};


#endif //ALGORITHMS_BINARYSEARCHTREE_H
