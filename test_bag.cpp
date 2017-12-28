//
// Created by Bourne on 2017/12/28.
//

#include <iostream>

#include "bag.h"

using namespace std;

int main(int argc, char* argv[])
{
    Bag<int> ibag;
    ibag.add(17);
    ibag.add(19);
    ibag.add(23);
    cout << ibag.size() << endl;
    return 0;
}