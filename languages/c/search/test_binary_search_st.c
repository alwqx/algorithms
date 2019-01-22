#include <stdlib.h>
#include <stdio.h>

#include "st.h"

int test_bst() {
    // test get_bst
    BinarySearchST *bst = get_bst();
    bst_display(bst);
    if(bst == NULL) {
        printf("get_bst() error, bst should not be NULL");
        exit(-1);
    }
    if(bst->size != 0) {
        printf("get_bst() error, size should be 0");
        exit(-1);
    }
    if(bst->cap != 2) {
        printf("get_bst() error, cap should be 2");
        exit(-1);
    }
    printf("test get_bst success\n");

    // test bst_empty
    if(!bst_empty(bst)) {
        printf("bst_empty error, bst is empty");
        exit(-1);
    }
    bst_put(bst, "name", 10);
    bst_put(bst, "age", 12);
    if(bst_empty(bst)) {
        printf("bst_empty error, bst should not be empty");
        exit(-1);
    }
    printf("test bst_empty success\n");

    // test bst_size
    if(bst_size(bst) != 2) {
        printf("bst_size error, size should be 2");
        exit(-1);
    }
    printf("test bst_size success\n");

    // test bst_resize
    // [name, 10]-[age, 12], size=2, cap=2
    bst_put(bst, "mail", 3);
    if(bst->size != 3) {
        printf("bst_resize error, size should be 3");
        exit(-1);
    }
    if(bst->cap != 4) {
        printf("bst_resize error, cap should be 4");
        exit(-1);
    }
    bst_delete(bst, "mail");
    bst_delete(bst, "age");
    if(bst->size != 1) {
        printf("bst_resize error, size should be 1");
        exit(-1);
    }
    if(bst->cap != 2) {
        printf("bst_resize error, cap should be 2");
        exit(-1);
    }
    printf("test bst_resize success\n");

    // test bst_put
    bst_put(bst, "age", 15);
    bst_put(bst, "girl", 16);
    bst_display(bst);
    if(bst->cap != 4) {
        printf("bst_put error, cap should be 4");
        exit(-1);
    }
    if(bst->size != 3) {
        printf("bst_put error, size should be 3");
        exit(-1);
    }
    printf("test bst_put() success\n");

    // test bst_get
    int ret = bst_get(bst, "name");
    if(ret != 10) {
        printf("bst_get error, ret of name should be 10");
        exit(-1);
    }
    ret = bst_get(bst, "girl");
    if(ret != 16) {
        printf("bst_get error, ret of girl should be 16");
        exit(-1);
    }
    printf("test bst_get success\n");

    // test bst_delete
    bst_display(bst);
    // [name, 10]-[age, 15]-[girl, 16], size=3, cap=4
    bst_delete(bst, "name");
    if(bst_contains(bst, "name")) {
        printf("bst_delete error, bst should not contain key name");
        exit(-1);
    }
    if(bst->size != 2) {
        printf("bst_delete error, size should be 2");
        exit(-1);
    }
    printf("test bst_delete success\n");

    bst_display(bst);
    // test bst_contains
    if(bst_contains(bst, "lwq")) {
        printf("bst_contains error, should not contain key lwq");
        exit(-1);
    }
    if(bst_contains(bst, "name")) {
        printf("bst_contains error, should contain key name");
        exit(-1);
    }
    if(!bst_contains(bst, "age")) {
        printf("bst_contains error, should contain key age");
        exit(-1);
    }
    printf("test bst_contains success\n");

    return 0;
}

int main() {
    return test_bst();
}