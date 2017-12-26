//
// Created by Bourne on 2017/12/26.
//

#include <string>
#include <iostream>
#include "binary_search_tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    BinarySearchTree *bst = new BinarySearchTree();
    bst->put(10, "10");
    bst->put(9, "9");
    bst->put(11, "11");

    cout << bst->size() << endl;
    cout << bst->get(10) << endl;
    cout << bst->get(11) << endl;

    cout << bst->min() << endl;
    cout << bst->max() << endl;

    cout <<bst->floor(12) << endl;
    cout <<bst->ceiling(8) << endl;

    bst->Delete(10);
    cout << bst->size() << endl;

    return 0;
}