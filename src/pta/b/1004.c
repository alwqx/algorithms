// https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448
#include <stdio.h>
#include <string.h>

#define MAXN 12

struct stuType {
    char Name[MAXN];
    char No[MAXN];
    int Grade;
};

int main() {
    int i, N;
    scanf("%d", &N);
    struct stuType s, max, min;

    for(i=0; i<N; i++) {
        scanf("%s %s %d", s.Name, s.No, &s.Grade);
        if(i == 0)                      max = min = s;
        else if(s.Grade > max.Grade)    max = s;
        else if(s.Grade<min.Grade)      min = s;
    }

    printf("%s %s\n", max.Name, max.No);
    printf("%s %s\n", min.Name, min.No);
}

/*
int main() {
    int i, N;
    scanf("%d", &N);
    struct stuType s, max, min;
    max.Grade = -1;
    min.Grade = 101;
    for(i=0; i<N; i++) {
        scanf("%s %s %d", s.Name, s.No, &s.Grade);
        if(i == 0)                      max = min = s;
        else if(s.Grade > max.Grade) {
            max.Grade = s.Grade;
            strcpy(max.Name, s.Name);
            strcpy(max.No, s.No);
        } else if(s.Grade<min.Grade) {
            min.Grade = s.Grade;
            strcpy(min.Name, s.Name);
            strcpy(min.No, s.No);
        }
    }

    printf("%s %s\n", max.Name, max.No);
    printf("%s %s\n", min.Name, min.No);
}*/