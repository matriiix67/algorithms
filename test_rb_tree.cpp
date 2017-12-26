//
// Created by Bourne on 2017/12/26.
//
#include <iostream>
#include <string>

#include "red_black_tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    RedBlackTree* rb_tree = new RedBlackTree();
    rb_tree->put(10, "10");
    rb_tree->put(11, "11");
    rb_tree->put(9, "9");

    cout << rb_tree->get(9) << endl;
    cout << rb_tree->size() << endl;

    return 0;
}