/*
计算机专硕 上机题目
Problem C:大数排序，每个数字在-10^50~10^50，从小到大排序
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

struct Num {
    char s[60];
    bool isPositive;
    int digit;
    bool operator < (const Num &B) {
        if(isPositive && B.isPositive) {
            if(digit != B.digit) return digit<B.digit;
            return strcmp(s, B.s) < 0;
        } else if(!isPositive && !B.isPositive) {
            if(digit != B.digit) return digit>B.digit;
            return strcmp(s, B.s) > 0;
        } else {
            return B.isPositive;
        }
    }
} num [200000];

int main() {
    long i, n;
    scanf("%ld", &n);
    for(i=0; i<n; i++) {
        scanf("%s", num[i].s);
        if(num[i].s[0] == '-') num[i].isPositive = false;
        else num[i].isPositive = true;
        num[i].digit = strlen(num[i].s);
    }

    sort(num, num+n);
    for(i=0; i<n; i++)
        if(i==0) printf("%s", num[i].s);
        else printf(" %s", num[i].s);

    return 0;
}