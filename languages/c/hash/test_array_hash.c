#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int test_lph() {
    // test hash
    if(hash_code("abc", 3) != 0) {
        printf("hash of abc should be 3");
        exit(-1);
    }
    if(hash_code("2abc", 3) != 2) {
        printf("hash of 2abc should be 2");
        exit(-1);
    }
    printf("test hash_code success\n");

    // test get_lph_cap
    ArrayHash *h = get_lph_cap(2);
    if(h->size != 0) {
        printf("test get_lph_cap error, size should be 0");
        exit(-1);
    }
    if(h->cap != 2) {
        printf("test get_lph_cap error, cap should be 2");
        exit(-1);
    }
    printf("test get_lph_cap success\n");

    // test resize
    lph_resize(h, 4);
    if(h->size != 0) {
        printf("test lph_resize error, size should be 0");
        exit(-1);
    }
    if(h->cap != 4) {
        printf("test lph_resize error, cap should be 4");
        exit(-1);
    }
    lph_resize(h, 2);
    if(h->size != 0) {
        printf("test lph_resize error, size should be 0");
        exit(-1);
    }
    if(h->cap != 2) {
        printf("test lph_resize error, cap should be 2");
        exit(-1);
    }
    printf("test lph_resize success\n");

    // test size
    if(lph_size(h) != 0) {
        printf("test lph_size error, size should be 0");
        exit(-1);
    }
    printf("test lph_size success\n");

    // test empty
    if(lph_empty(h) != 0) {
        printf("test lph_empty error, h should be empty");
        exit(-1);
    }
    printf("test lph_empty success\n");

    // test put
    lph_put(h, "name", 1);
    if(h->size != 1) {
        printf("test lph_put error, size should be 1");
        exit(-1);
    }
    if(h->cap != 2) {
        printf("test lph_put error, cap should be 2");
        exit(-1);
    }
    lph_put(h, "age", 10);
    if(h->cap != 4) {
        printf("test lph_put error, cap should be 8");
        exit(-1);
    }
    lph_put(h, "sex", 1);
    if(h->cap != 8) {
        printf("test lph_put error, cap should be 8");
        exit(-1);
    }
    if(h->size != 3) {
        printf("test lph_put error, size should be 3");
        exit(-1);
    }
    lph_display(h);
    printf("test lph_put success\n");

    // test lph_get
    int ret = lph_get(h, "name");
    if(ret != 1) {
        printf("test lph_get error, value of key name should be 1");
        exit(-1);
    }
    ret = lph_get(h, "age");
    if(ret != 10) {
        printf("test lph_get error, value of key name should be 1");
        exit(-1);
    }
    printf("test lph_get success\n");

    // test contains
    lph_display(h);
    ret = lph_contains(h, "name");
    if(!ret) {
        printf("test lph_contains error, hash should contain key name");
        exit(-1);
    }
    ret = lph_contains(h, "age");
    if(!ret) {
        printf("test lph_contains error, hash should contain key age");
        exit(-1);
    }
    ret = lph_contains(h, "bq");
    if(ret) {
        printf("test lph_contains error, hash should not contain key bq");
        exit(-1);
    }
    printf("test lph_contains success\n");

    // test lph_delete
    lph_put(h, "lwq", 23);
    // [age, 10] [name, 1] [sex, 1]
    lph_delete(h, "name");
    if(lph_contains(h, "name")) {
        printf("test lph_delete error, hash should not contain key name");
        exit(-1);
    }
    if(h->cap != 8) {
        printf("test lph_delete error, cap should be 8");
        exit(-1);
    }
    // [age, 10] [lwq, 23] [sex, 1]
    lph_delete(h, "age");
    lph_delete(h, "sex");
    if(lph_contains(h, "sex")) {
        printf("test lph_delete error, hash should not contain key sex");
        exit(-1);
    }
    if(lph_contains(h, "age")) {
        printf("test lph_delete error, hash should not contain key age");
        exit(-1);
    }
    if(h->cap != 4) {
        printf("test lph_delete error, cap should be 4");
        exit(-1);
    }
    printf("test lph_delete success\n");

    return 0;
}

int main() {
    return test_lph();
}