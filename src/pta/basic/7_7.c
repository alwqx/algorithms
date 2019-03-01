// https://pintia.cn/problem-sets/14/problems/787

#include <stdio.h>

int main(){
    int minute,hour;
    scanf("%d:%d",&hour, &minute);

    if(hour>=0&&hour<12){
        printf("%d:%d AM",hour,minute);
    }else if(hour==12){
        printf("12:%d PM",minute);
    }else {
        printf("%d:%d PM",hour-12,minute);
    }

    return 0;
}