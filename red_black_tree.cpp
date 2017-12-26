//
// Created by Bourne on 2017/12/26.
//

#include <string>
#include "red_black_tree.h"
using namespace std;

RedBlackTree::Node * RedBlackTree::rotate_left(Node *node)
{
    Node* x = node->right_;
    node->right_ = x->left_;
    x->left_ = node;
    x->color_ = node->color_;
    node->color_ = RED;
    x->size_ = node->size_;
    node->size_ = 1 + size(node->left_) + size(node->right_);
    return x;
}

RedBlackTree::Node * RedBlackTree::rotate_right(Node *node)
{
    Node* x = node->left_;
    node->left_ = x->right_;
    x->right_ = node;
    x->color_ = node->color_;
    node->color_ = RED;
    x->size_ = node->size_;
    node->size_ = 1 + size(node->left_) + size(node->right_);
    return x;
}

string RedBlackTree::get(int key)
{
    return get(root_, key);
}

string RedBlackTree::get(Node *root, int key)
{
    if(root == nullptr) {
        return nullptr;
    }

    if(key < root->key_) {
        return get(root->left_, key);
    } else if(key > root->key_) {
        return get(root->right_, key);
    } else {
        return root->value_;
    }
}

void RedBlackTree::put(int key, string value)
{
    root_ = put(root_, key, value);
    root_->color_ = BLACK;
}

void RedBlackTree::flip_colors(Node *node)
{
    node->color_ = RED;
    node->left_->color_ = BLACK;
    node->right_->color_ = BLACK;
}

RedBlackTree::Node * RedBlackTree::put(Node *node, int key, string value)
{
    if(node == nullptr) {
        return new Node(key, value, 1, RED);
    }

    if(key < node->key_) {
        node->left_ = put(node->left_, key, value);
    } else if(node->key_ < key) {
        node->right_ = put(node->right_, key, value);
    } else {
        node->value_ = value;
    }

    if(is_red(node->right_) && !is_red(node->left_)) {
        node = rotate_left(node);
    }

    if(is_red(node->left_) && !is_red(node->right_)) {
        node = rotate_right(node);
    }

    if(is_red(node->left_) && is_red(node->right_)) {
        flip_colors(node);
    }

    node->size_ = size(node->left_) + size(node->right_) + 1;
    return node;


}
