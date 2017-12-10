//
// Created by Bourne on 2017/12/3.
//


#include <stdlib.h>
#include <string.h>

#include "sort.h"

int issort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
    char *a = data;
    void *key;
    int i, j;

    if(key = (char *)malloc(sizeof(esize)) == NULL) {
        return -1;
    }

    for(j = 1; j < size ; j++) {
        memcpy(key, &a[j * esize], esize);
        i = j - 1;

        while (i > 0 && compare(&a[i * esize] , key) > 0) {
            memcpy(&a[(i + 1) * esize], &a[i * esize], esize);
            i--;
        }
        memcpy(&a[(i + 1) *esize], key, esize);
    }

    free(key);
    return 0;
}

static int compare_int(const void *int1, const void *int2) {
    if(*(const int *)int1 > *(const int *)int2)
        return 1;
    else if(*(const int *)int1 < *(const int *)int2)
        return -1;
    else return 0;
}


static int partition(void *data, int esize, int i, int k, int (*compare)(const void *key1, const void *key2)) {
    char *a = data;
    void *pval;
    void *temp;
    int r[3];

    if((pval = malloc(esize)) == NULL)
        return -1;

    if((temp = malloc(esize)) == NULL) {
        free(pval);
        return -1;
    }

    r[0] = (rand() % (k - i + 1)) + i;
    r[1] = (rand() % (k - i + 1)) + i;
    r[2] = (rand() % (k - i + 1)) + i;
    issort(r, 3, sizeof(int), compare_int);
    memcpy(pval, &a[r[1] * esize], esize);

    i--;
    k++;

    while(1) {
        do {
            k--;
        } while(compare(&a[k * esize], pval) > 0);

        do {
            i++;
        } while(compare(&a[i * esize], pval) < 0);

        if(i >= k) {
            break;
        } else {
            memcpy(temp, &a[i * esize], esize);
            memcpy(&a[i * esize], &a[k * esize], esize);
            memcpy(&a[k * esize], temp, esize);
        }
    }

    free(pval);
    free(temp);

    return k;
}


int qksort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2)) {
    int j;
    while(i < k) {
        if((j = partition(data, esize, i, k, compare)) < 0)
            return -1;

        if(qksort(data, size, esize, i, j, compare) < 0)
            return -1;

        i = j + 1;
    }

    return 0;
}


static int merge(void *data, int esize, int i, int j, int k, int (*compare)(const void *key1, const void *key2)) {
    char *a = data;
    char *m;
    int ipos;
    int jpos;
    int mpos;

    ipos = i;
    jpos = j + 1;
    mpos = 0;

    if((m = (char *)malloc(esize * ((k - i) + 1))) == NULL) {
        return -1;
    }

    while(ipos <= j || jpos <= k) {
        if(ipos > j) {
            while(jpos <= k) {
                memcpy(&m[mpos * esize], &a[jpos *esize], esize);
                jpos++;
                mpos++;
            }
            continue;
        } else if (jpos > k){
            while(ipos <= j) {
                memcpy(&m[mpos * esize], &a[ipos * esize], esize);
                ipos++;
                mpos++;
            }
            continue;
        }

        if(compare(&a[ipos * esize], &a[jpos *esize]) < 0) {
            memcpy(&m[mpos * esize], &a[ipos * esize], esize);
            ipos++;
            mpos++;
        } else {
            memcpy(&m[mpos * esize], &a[jpos * esize], esize);
            jpos++;
            mpos++;
        }
    }

    memcpy(&a[i * esize], m, esize * ((k - i) + 1));

    free(m);

    return 0;
}


int mgsort(void *data, int size, int esize, int i, int k, int (*compare)(const void *key1, const void *key2)) {
    int j;

    if(i < k) {
        j = (int)((i + k - 1)/2);
        if(mgsort(data, size, esize, i, j, compare) < 0) {
            return -1;
        }

        if(mgsort(data, size, esize, j + 1, k, compare) < 0) {
            return -1;
        }

        if(merge(data, esize, i, j, k, compare) < 0) {
            return -1;
        }
    }
    return 0;
}


int bisearch(void *sorted, const void *targe, int size, int esize, int (*compare)(const void *key1, const void *key2)) {
    int left, middle, right;

    left = 0;
    right = size - 1;

    while(left <= right) {
        middle = (left + right) / 2;

        switch(compare(((char *)sorted + (esize + middle)), targe)) {
            case -1:
                left = middle + 1;
                break;
            case 1:
                right = middle - 1;
                break;
            case 0:
                return middle;
        }
    }

    return -1;
}