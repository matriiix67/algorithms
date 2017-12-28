//
// Created by Bourne on 2017/12/10.
//
#include <iostream>
#include <vector>

#include "sort.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "hello, world!" << std::endl;
    vector<int> ivec = {9, 1, 2, 6, 4, 7, 8, 3, 5};
    Sort<int> sort;

    sort.selection_sort(ivec);

    cout << "selection sort result: ";
    for(int e : ivec) {
        cout << e << " ";
    }
    cout << endl;

    // insertion sort
    ivec = {9, 1, 2, 6, 4, 7, 8, 3, 5};
    sort.insertion_sort(ivec);

    cout << "insertion sort result: ";
    for(int e : ivec) {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}