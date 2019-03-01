// https://pintia.cn/problem-sets/14/problems/810

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10

typedef struct {
    char *s;
} Record;

int main() {
    int i, j, N, K;
    scanf("%d %d", &N, &K);
    Record *rec;
    rec = (Record *) malloc(sizeof(Record)*N);
    for(i=0; i<N; i++) {
        rec[i].s = (char *) malloc(sizeof(char *)*MAXN);
        scanf("%s", rec[i].s);
    }

    // K th bubble sort
    char *tmp;
    for(j=N-1; j>=N-K; j--) {
        for(i=0; i<j; i++)
            if(strcmp(rec[i].s, rec[i+1].s)>0) {
                tmp = rec[i].s;
                rec[i].s = rec[i+1].s;
                rec[i+1].s = tmp;
            }
    }

    for(i=0; i<N; i++)
        printf("%s\n", rec[i].s);

    return 0;
}