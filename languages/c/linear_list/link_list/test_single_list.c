#include <stdlib.h>

#include "list.h"

int test_single_list() {
    LinkList *list = get_single_list();

    // test insert
    list_insert(list, 4); // [4]
    list_insert(list, 9); // [9, 4]
    list_insert(list, 3); // [3, 9, 4]
    list_insert(list, 1); // [1, 3, 9, 4]
    if(list->size != 4) {
        printf("insert error, size should be 4, but get %d\n", list->size);
        exit(-1);
    }
    printf("test insert success\n");

    // test remove
    int ret = list_remove_index(list, 0); // [3, 9, 4]
    if(ret != 1){
        printf("list remove error, should remove 1, but remove %d\n", ret);
        exit(-1);
    }
    ret = list_remove_index(list, 2); // [3, 9]
    if(ret != 4){
        printf("list remove error, should remove 4, but remove %d\n", ret);
        exit(-1);
    }
    ret = list_remove_value(list, 3); // [9]
    if(ret != 3){
        printf("list remove error, should remove 3, but remove %d\n", ret);
        exit(-1);
    }
    printf("test remove success\n");

    // test find
    list_insert(list, 4);
    list_insert(list, 12);
    list_insert(list, 3);
    list_insert(list, 1); // [1, 3, 12, 4, 9]
    LNode *s;
    s = list_find_index(list, 2);
    if(s->data != 12){
        printf("list find index error, shoud be 12, but get %d\n", s->data);
        exit(-1);
    }
    s = list_find_value(list, 9);
    if(s->data != 9) {
        printf("list find value error, shoud be 9, but get %d\n", s->data);
        exit(-1);
    }
    printf("test find success\n");

    // test find max min
    ret = list_find_max(list);
    if(ret!=12){
        printf("list find max error, should be 12, but get %d\n", ret);
        exit(-1);
    }
    ret = list_find_min(list);
    if(ret!=1){
        printf("list find max error, should be 1, but get %d\n", ret);
        exit(-1);
    }
    printf("list find min max success\n");

    // test update
    list_update(list, 0, 10); // [10, 3, 12, 4, 9]
    if(list->first->data != 10) {
        printf("list update error, new value should be 10, but get %d\n", list->first->data);
        exit(-1);
    }
    list_update(list, 1, 1); // [10, 3, 12, 4, 9]
    if(list->first->next->data != 1) {
        printf("list update error, new value should be 1, but get %d\n", list->first->next->data);
        exit(-1);
    }
    printf("list update success\n");

    list_display(list);

    return 0;
}

int main() {
    return test_single_list();
}