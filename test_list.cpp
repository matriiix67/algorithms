//
// Created by Bourne on 2017/12/27.
//

#include "list.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    List<int> ilist;
    ilist.push_front(19);
    ilist.push_front(20);
    ilist.push_front(21);
    ilist.push_front(22);

    cout << ilist.pop_front() << endl;
    cout << ilist.pop_front() << endl;
    return 0;
}