//
// Created by Bourne on 2017/12/3.
//

#ifndef ALGORITHMS_SORT_H
#define ALGORITHMS_SORT_H

#include <stdlib.h>

// insert sort
// esize: element size
int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

// quick sort
int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

int bisearch(void *sorted, const void *targe, int size, int esize, int (*compare)(const void *key1, const void *key2));

int mgsort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2));

#endif //ALGORITHMS_SORT_H
