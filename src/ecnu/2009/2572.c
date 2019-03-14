// https://eoj.i64d.com/problem/2572/
#include <stdio.h>
#include <stdlib.h>

void qqsort(long int *a, long int left, long int right);

int main() {
    long int i, n;
    scanf("%ld", &n);
    long int *a = (long int *) malloc(sizeof(long int)*n);

    for(i=0; i<n; i++) {
        scanf("%ld", &a[i]);
    }
    qqsort(a, 0, n-1);

    int j, k, m;
    scanf("%d", &k);
    for(j=0; j<k; j++) {
        scanf("%d", &m);
        printf("%ld\n", a[m-1]);
    }

    return 0;
}

void swap(long int *a, long int i, long int j) {
    long int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

void qqsort(long int *a, long int left, long int right) {
    if(left >= right) return;
    long int i, last;
    swap(a, left, (left+right)/2);
    last = left;
    
    for(i=left+1; i<=right; i++)
        if(a[i]<a[left]) swap(a, i, ++last);
    swap(a, left, last);

    qqsort(a, left, last-1);
    qqsort(a, last+1, right);
}