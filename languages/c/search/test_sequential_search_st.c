#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "st.h"

int test_sst() {
    // test get_sst
    SequentialSearchST *st = get_sst();
    if(st == NULL) {
        printf("get_sst error, sst is null");
        exit(-1);
    }
    if(st->size != 0) {
        printf("get_sst error, size should be 0");
        exit(-1);
    }
    if(st->first != NULL) {
        printf("get_sst error, first should be null");
        exit(-1);
    }
    printf("test get_sst success\n");

    // test size
    if(sst_size(st) != 0) {
        printf("sst_size error, size should be 0");
        exit(-1);
    }
    printf("test sst_size success\n");

    // test empty
    if(!sst_empty(st)) {
        printf("sst_empty error, st shoule be empty");
        exit(-1);
    }
    printf("test sst_empty success\n");

    // test put
    sst_put(st, "name", 1);
    sst_put(st, "age", 11);
    sst_put(st, "mail", 2);
    if(sst_size(st) != 3) {
        printf("sst_put error, size should be 3");
        exit(-1);
    }
    printf("test sst_put success\n");

    // test get
    int ret = sst_get(st, "name");
    if(ret != 1) {
        printf("sst_get error, ret should be 0");
        exit(-1);
    }
    ret = sst_get(st, "age");
    if(ret != 11) {
        printf("sst_get error, ret should be 11");
        exit(-1);
    }
    printf("test sst_get success\n");

    // test contains
    ret = sst_contains(st, "name");
    if(!ret) {
        printf("sst_contains error, st should contain key name");
        exit(-1);
    }
    ret = sst_contains(st, "age");
    if(!ret) {
        printf("sst_contains error, st should contain key age");
        exit(-1);
    }
    ret = sst_contains(st, "mail");
    if(!ret) {
        printf("sst_contains error, st should contain key mail");
        exit(-1);
    }
    ret = sst_contains(st, "height");
    if(ret) {
        printf("sst_contains error, st should not contain key height");
        exit(-1);
    }
    printf("test sst_contains success\n");

    // test delete
    sst_display(st);
    sst_delete(st, "name");
    ret = sst_contains(st, "name");
    if(ret) {
        printf("sst_delete error, st should not contain key name");
        exit(-1);
    }
    sst_delete(st, "age");
    ret = sst_contains(st, "age");
    if(ret) {
        printf("sst_delete error, st should not contain key age");
        exit(-1);
    }
    if(sst_size(st) != 1) {
        printf("sst_delete error, size should be 1");
        exit(-1);
    }
    sst_delete(st, "age");
    ret = sst_contains(st, "age");
    if(ret) {
        printf("sst_delete error, st should not contain key age");
        exit(-1);
    }
    sst_delete(st, "mail");
    ret = sst_contains(st, "mail");
    if(ret) {
        printf("sst_delete error, st should not contain key mail");
        exit(-1);
    }
    if(!sst_empty(st))
    {
        printf("sst_delete error, st should be empty");
        exit(-1);
    }
    printf("test sst_delete success\n");

    // test sst_get_node
    sst_put(st, "name", 45);
    STNode *x = sst_get_node(st, "name");
    if(strcmp(x->key, "name") != 0) {
        printf("sst_get_node error, key should be name");
        exit(-1);
    }
    if(x->value != 45) {
        printf("sst_get_node error, value should be 45");
        exit(-1);
    }
    printf("test sst_get_node success\n");

    return 0;
}

int main() {
    return test_sst();
}