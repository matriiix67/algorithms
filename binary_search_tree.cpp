//
// Created by Bourne on 2017/12/26.
//

#include <string>

#include "binary_search_tree.h"

using namespace std;

string BinarySearchTree::get(int key)
{
    return get(root_, key);
}

string BinarySearchTree::get(Node *root, int key)
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


void BinarySearchTree::put(int key, string value)
{
    root_ = put(root_, key, value);
}


BinarySearchTree::Node * BinarySearchTree::put(Node* root, int key, string value)
{
    if(root == nullptr)
        return new Node(key, value, 1);

    if(key < root->key_) {
        root->left_ = put(root->left_, key, value);
    } else if(key > root->key_) {
        root->right_ = put(root->right_, key, value);
    } else {
        root->value_ = value;
    }

    int left_size = size(root->left_);
    int right_size = size(root->right_);

    root->size_ = size(root->left_) + size(root->right_) + 1;
    return root;
}

int BinarySearchTree::min()
{
    return min(root_)->key_;
}

BinarySearchTree::Node * BinarySearchTree::min(Node *root)
{
    if(root->left_ == nullptr) return root;

    return min(root->left_);
}

int BinarySearchTree::floor(int key)
{
    Node* x = floor(root_, key);
    if(x == nullptr) return 0;
    return x->key_;
}

BinarySearchTree::Node * BinarySearchTree::floor(Node *root, int key)
{
    if(root == nullptr) return nullptr;
    if(key == root->key_)
        return root;

    if(key < root->key_) {
        return floor(root->left_, key);
    }

    Node* t = floor(root->right_, key);
    if(t != nullptr) return t;
    else return root;
}

int BinarySearchTree::max()
{
    return max(root_)->key_ ;
}

BinarySearchTree::Node * BinarySearchTree::max(Node *root)
{
    if(root->right_ == nullptr) return root;
    return max(root->right_);
}

int BinarySearchTree::ceiling(int key)
{
    Node* x = ceiling(root_, key);
    if(x ==  nullptr)
        return 0;
    return x->key_;
}

BinarySearchTree::Node * BinarySearchTree::ceiling(Node *root, int key)
{
    if(root == nullptr) return nullptr;

    if(key == root->key_)
        return root;

    if(key > root->key_)
        return ceiling(root->right_, key);

    Node* t = ceiling(root->left_, key);
    if(t != nullptr) return t;
    else return root;
}

int BinarySearchTree::select(int k)
{
    return select(root_, k)->key_;
}

BinarySearchTree::Node * BinarySearchTree::select(Node *root, int k)
{
    if(root == nullptr) return nullptr;
    int t = size(root->left_);
    if(t > k) return select(root->left_, k);
    else if(t < k) return select(root->right_, k - t - 1);
    else return  root;
}

int BinarySearchTree::rank(int key)
{
    return rank(root_, key);
}

int BinarySearchTree::rank(Node *root, int key)
{
    if(root == nullptr) return 0;
    if(key < root->key_) {
        return rank(root->left_, key);
    } else if (key > root->key_) {
        return rank(root->right_, key);
    } else {
        return size(root->left_);
    }
}

void BinarySearchTree::DeleteMin()
{
    root_ = DeleteMin(root_);
}

BinarySearchTree::Node * BinarySearchTree::DeleteMin(Node *root)
{
    if(root->left_ == nullptr) return root->right_;
    root->left_ = DeleteMin(root->left_);
    root->size_ = size(root->left_) + size(root->right_) + 1;
    return root;
}

void BinarySearchTree::Delete(int key)
{
    root_ = Delete(root_, key);
}

BinarySearchTree::Node * BinarySearchTree::Delete(Node *root, int key)
{
    if(root == nullptr) return nullptr;

    if(key < root->key_) {
        root->left_ = Delete(root->left_, key);
    } else if (key > root->key_) {
        root->right_ = Delete(root->right_, key);
    } else {
        if(root->right_ == nullptr) return root->left_;
        if(root->left_ == nullptr) return root->right_;
        Node* t = root;
        root = min(root->right_);
        root->right_ = DeleteMin(t->right_);
        root->left_ = t->left_;
    }
    root->size_ = size(root->left_) + size(root->right_) + 1;
    return root;
}