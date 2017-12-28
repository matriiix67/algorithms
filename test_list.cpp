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
    ilist.push_front(22).push_front(23).push_front(18);

//    ilist.remove(1);

    cout << ilist.find(19) << endl;

    cout << ilist.max() << endl;

    cout << ilist.pop_front() << endl;
    cout << ilist.pop_front() << endl;
    cout << ilist.pop_front() << endl;
    cout << ilist.pop_front() << endl;

    ilist.reverse();
    cout << ilist.pop_front() << endl;
    cout << ilist.pop_front() << endl;

    return 0;
}