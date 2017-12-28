//
// Created by Bourne on 2017/12/28.
//

#include <iostream>

#include "queue.h"

using namespace std;

int main(int argc, char* argv[])
{
    Queue<int> iqueue;
    iqueue.enqueue(17);
    iqueue.enqueue(19);
    iqueue.enqueue(23);

    cout << iqueue.size() << endl;

    cout << iqueue.dequeue() << endl;
    cout << iqueue.size() << endl;

    return 0;
}