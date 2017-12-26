//
// Created by Bourne on 2017/12/26.
//

#ifndef ALGORITHMS_RED_BLACK_TREE_H
#define ALGORITHMS_RED_BLACK_TREE_H

#include <string>
using namespace std;

class RedBlackTree
{
public:
    RedBlackTree() : root_(nullptr) {

    }

    ~RedBlackTree(){
        destroy(root_);
    }
    int size()
    {
        return size(root_);
    }
    string get(int key);
    void put(int key, string value);
private:
    static const bool RED = true;
    static const bool BLACK = false;
    class Node {
    public:
        Node(int key, string value, int size, bool color)
                : key_(key), value_(value), size_(size), color_(color), left_(nullptr), right_(nullptr) {

        }

    public:
        int key_;
        string value_;
        Node* left_;
        Node* right_;
        int size_;
        bool color_;

    };

    bool is_red(Node* node) {
        if(node == nullptr) return false;
        return node->color_ == RED;
    }

    Node* root_;

    int size(Node* root)
    {
        if(root == nullptr) {
            return 0;
        } else
            return root->size_;
    }

    Node* rotate_left(Node* node);
    Node* rotate_right(Node* node);
    void flip_colors(Node* node);
    string get(Node *root, int key);
    Node* put(Node* node, int key, string value);

    void destroy(Node* node);
};


#endif //ALGORITHMS_RED_BLACK_TREE_H
