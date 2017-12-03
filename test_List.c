//
// Created by Bourne on 2017/11/29.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char* argv[])
{
    List *list = (List *)malloc(sizeof(List));
    list_init(list, NULL);
    list_ins_next(list, NULL, 1);
    list_ins_next(list, NULL, 2);
    list_ins_next(list, NULL, 3);

    printf("list size: %d\n", (int)list_size(list));
    printf("list head: %d\n", (int)list_head(list)->data);
    printf("list tail: %d\n", (int)list_tail(list)->data);

    int *data = NULL;
    list_rem_next(list, NULL, &data);

    printf("list size: %d\n", (int)list_size(list));
    printf("list head: %d\n", (int)list_head(list)->data);
    printf("list head: %d\n", (int)list_tail(list)->data);

    return 0;
}

