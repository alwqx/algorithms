#include <stdio.h>

// https://pintia.cn/problem-sets/14/problems/743
#define MAXN 3
typedef float ElementType;

ElementType Median(ElementType A[], int N);

int main() {
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%f", &A[i]);

    printf("%.2f\n", Median(A, N));
    return 0;
}

// sulotion 1: selection sort, not passed for Bug N
/*
ElementType Median(ElementType A[], int N) {
    int i, j, index;
    ElementType tmp, max;

    for(i=0; i<N; i++) {
        index = i;
        max = A[i];
        for(j=i+1; j<N; j++) {
            if(max>A[j]) {
                index=j;
                max=A[j];
            }
        }
        if(i!=index) {
            A[index] = A[i];
            A[i] = max;
        }
    }

    return A[N/2];
}
*/

// solution 2: shell sort
ElementType Median(ElementType A[], int N) {
    int i, j, h=1;
    while(h<N/3) h=3*h+1;
    ElementType tmp;

    while(h>=1) {
        for(i=h; i<N; i++) {
            for(j=i; j>=h&&A[j]<A[j-h]; j-=h){
                tmp = A[j];
                A[j] = A[j-h];
                A[j-h] = tmp;
            }
        }
        h/=3;
    }

    // for(i=0; i<N; i++)
    //     printf("%.2f ", A[i]);
    // putchar('\n');

    return A[N/2];
}

/*
ElementType Median( ElementType A[], int N){
    int i, j, p;
    ElementType s;
 
    //将数组排序
    for ( p = N / 2; p > 0; p /= 2){
        for ( i = p; i < N; i++){
            s = A[ i ];
            for (j = i;j >= p;j -= p ){
                if ( s < A[ j - p ])
                    A[ j ] = A[ j - p ];
                else
                    break;
            }
            A[ j ] = s;
        }
    }
 
    return A[ N / 2 ];
}
*/