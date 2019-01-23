#include <stdlib.h>
#include <stdio.h>

#include "hash.h"

int test_lh() {
    // test get_lh_cap
    LinkedHash *h = get_linked_hash_cap(LINKED_HASH_INIT_CAP*2);
    if(h->cap != 8) {
        printf("get_linked_hash_cap error, cap should be 8");
        exit(-1);
    }
    if(h->size != 0) {
        printf("get_linked_hash_cap error, size should be 0");
        exit(-1);
    }
    h = get_linked_hash_cap(LINKED_HASH_INIT_CAP);
    if(h->cap != 4) {
        printf("get_linked_hash_cap error, cap should be 4");
        exit(-1);
    }
    if(h->size != 0) {
        printf("get_linked_hash_cap error, size should be 0");
        exit(-1);
    }
    printf("test get_linked_hash_cap success\n");

    // test resize
    lh_resize(h, 2);
    if(h->cap != 2) {
        printf("lh_resize error, cap should be 2");
        exit(-1);
    }
    if(h->size != 0) {
        printf("lh_resize error, size should be 0");
        exit(-1);
    }
    lh_resize(h, 4);
    if(h->cap != 4) {
        printf("lh_resize error, cap should be 4");
        exit(-1);
    }
    if(h->size != 0) {
        printf("lh_resize error, size should be 0");
        exit(-1);
    }
    printf("test lh_resize success\n");

    // test lh_size
    if(lh_size(h) != 0) {
        printf("lh_size error, size should be 0");
        exit(-1);
    }
    printf("test lh_size success\n");

    // test lh_empty
    if(lh_empty(h) != 0) {
        printf("lh_empty error, linked_hash should be empty");
        exit(-1);
    }
    printf("test lh_empty success\n");

    // test lh_put
    lh_put(h, "name", 12);
    lh_put(h, "age", 23);
    if(h->size != 2) {
        printf("lh_put error, size should be 2");
        exit(-1);
    }
    if(h->cap != 4) {
        printf("lh_put error, cap should be 4");
        exit(-1);
    }
    printf("test lh_put success\n");

    // test get
    lh_display(h);
    int ret = lh_get(h, "name");
    if(ret != 12) {
        printf("lh_get error, ret of key name should be 12");
        exit(-1);
    }
    ret = lh_get(h, "age");
    if(ret != 23) {
        printf("lh_get error, ret of key age should be 23");
        exit(-1);
    }
    printf("test lh_get success\n");

    // test lh_contains
    if(lh_contains(h, "abc")) {
        printf("lh_contains error, should not contain key abc");
        exit(-1);
    }
    if(!lh_contains(h, "name")) {
        printf("lh_contains error, should contain key name");
        exit(-1);
    }
    printf("test lh_contains success\n");

    // test lh_delete
    lh_put(h, "aaa", 12);
    lh_put(h, "bbb", 112);
    lh_put(h, "cc", 120);
    lh_display(h);
    if(h->size != 5) {
        printf("lh_delete error, size should be 5");
        exit(-1);
    }
    lh_delete(h, "aaa");
    if(lh_contains(h, "aaa")) {
        printf("lh_delete error, should not contain key aaa");
        exit(-1);
    }
    lh_delete(h, "bbb");
    if(lh_contains(h, "bbb")) {
        printf("lh_delete error, should not contain key bbb");
        exit(-1);
    }
    printf("test lh_delete success\n");

    return 0;
}

int main() {
    return test_lh();
}