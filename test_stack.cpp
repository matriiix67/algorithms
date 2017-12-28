//
// Created by Bourne on 2017/12/28.
//

#include <iostream>

#include "stack.h"

using namespace std;

int main(int argc, char* argv[])
{
    Stack<int> stack;
    stack.push(17);
    stack.push(19);
    stack.push(23);

    cout << stack.size() << endl;
    return 0;
}
