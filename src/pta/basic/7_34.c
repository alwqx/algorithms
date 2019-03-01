// https://pintia.cn/problem-sets/14/problems/814

#include <stdio.h>
#include <stdlib.h>
#define MAXN 20

typedef struct peo {
    char name[MAXN];
    char date[MAXN];
    char sex;
    char tel[MAXN]; // 固定电话号码
    char pho[MAXN]; // 移动电话号码
} Record;

int main() {
    int i, N;
    scanf("%d", &N);

    Record *rec;
    rec = (Record *) malloc(sizeof(Record)*N);
    
    for(i=0; i<N; i++) {
        scanf("%s %s %c %s %s", rec[i].name, rec[i].date, &rec[i].sex,
            rec[i].tel, rec[i].pho);
    }
    
    int K, *s;
    scanf("%d", &K);
    s = (int *) malloc(sizeof(int)*K);
    for(i=0; i<K; i++)
        scanf("%d", &s[i]);

    int j;
    for(i=0; i<K; i++) {
        j = s[i];
        if(j<0 || j>=N) {
            printf("Not Found\n");
        } else {
            printf("%s %s %s %c %s\n", rec[j].name, rec[j].tel, rec[j].pho,
                rec[j].sex, rec[j].date);
        }
    }

    return 0;
}