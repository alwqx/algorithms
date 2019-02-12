#include <stdlib.h>
#include <stdio.h>

#include "array.h"

int test_static_array(){
    SqList *sp = get_static_array();

    // test array_insert
    array_insert(sp, 0, 1); // s=[1]
    if(sp->length != 1) {
        printf("%s\n", "length should be 1");
        exit(-1);
    }
    array_insert(sp, 1, 2); // s=[1, 2]
    if(sp->data[1] != 2) {
        printf("%s\n", "data 1 should be 2");
        exit(-1);
    }
    array_insert(sp, 1, 3); // s=[1, 3, 2]
    if(sp->data[2] != 2) {
        printf("%s\n", "data 2 should be 1");
        exit(-1);
    }
    printf("%s\n", "test array insert success");

    // test array update
    array_update(sp, 0, 5); // s=[5, 3, 2]
    if(sp->data[0] != 5){
        printf("%s\n", "update error, data 0 should be 5");
        exit(-1);
    }
    array_update(sp, 2, 12); // s=[5, 3, 12]
    if(sp->data[2] != 12){
        printf("%s\n", "update error, data 2 should be 12");
        exit(-1);
    }
    printf("%s\n", "test array update success");

    // test remove
    array_remove(sp, 0); // s=[3, 12]
    if(sp->length != 2){
        printf("%s\n", "remove error, length should be 2");
        exit(-1);
    }
    if(sp->data[0] != 3 || sp->data[1] != 12){
        printf("%s\n", "remove error, data error");
        exit(-1);
    }
    array_remove(sp, 1); // s=[3]
    if(sp->data[0] != 3){
        printf("%s\n", "remove error, data 0 should be 3");
        exit(-1);
    }
    if(sp->length != 1){
        printf("%s\n", "remove error, length should be 1");
        exit(-1);
    }
    printf("%s\n", "test array remove success");

    // test min and max
    array_insert(sp, 0, 2); // s=[2, 3]
    array_insert(sp, 0, -3); // s=[-3, 2, 3]
    array_insert(sp, 0, 12); // s=[12, -3, 2, 3]
    array_display(sp);
    if(array_min(sp) != -3){
        printf("%s\n", "min error, min should be -2");
        exit(-1);
    }
    if(array_max(sp) != 12){
        printf("%s\n", "max error, max should be 12");
        exit(-1);
    }
    printf("%s\n", "test min and max success");

    return 0;
}

int main(int argc, char *argv[]){
    return test_static_array();
}