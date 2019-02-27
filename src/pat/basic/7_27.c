// https://pintia.cn/problem-sets/14/problems/807

#include <stdio.h>
#include <stdlib.h>

void swap(int *data, int i, int j);

int main() {
    int i, j, K, N;
    int *data;
    scanf("%d %d", &N, &K);
    data = (int *) malloc(sizeof(int) * N);
    for(i=0; i<N; i++)
        scanf("%d", &data[i]);

    // bubble sort
    for(j=1; j<=K; j++) {
        for(i=0; i<N-j; i++)
            if(data[i]>data[i+1]) swap(data, i, i+1);
    }

    for(i=0; i<N-1; i++)
        printf("%d ", data[i]);
    printf("%d", data[i]);
    return 0;
}

void swap(int *data, int i, int j) {
    int tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
}