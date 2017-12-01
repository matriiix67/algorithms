//
// Created by Bourne on 2017/12/1.
//

#include <stdlib.h>
#include <stdio.h>

#include "dlist.h"

int main(int argc, char* argv[])
{
    DList *list = (DList *)malloc(sizeof(DList));
    dlist_init(list, NULL);
    dlist_ins_next(list, NULL, 1);
    dlist_ins_prev(list, dlist_head(list), 2);
    printf("dlist_size: %d\n", dlist_size(list));

    void *data;
    dlist_remove(list, dlist_head(list), &data);
    printf("dlist_size: %d\n", dlist_size(list));
    printf("data : %d\n", (int *)data);
    dlist_remove(list, dlist_head(list), &data);
    printf("dlist_size: %d\n", dlist_size(list));
    printf("data : %d\n", (int *)data);

    dlist_destroy(list);
    return 0;
}
