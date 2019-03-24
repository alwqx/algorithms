/*
计算机专硕 上机题目
Problem A:1+1
*/
#include <stdio.h>

int main() {
    int a, b;
    char op;
    scanf("%d %c %d", &a, &op, &b);
    int ret;

    switch(op) {
    case '+':
        ret = a+b;
        break;
    case '-':
        ret = a-b;
        break;
    case '*':
        ret = a*b;
    }

    printf("%d\n", ret);
}