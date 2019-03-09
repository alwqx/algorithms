// https://pintia.cn/problem-sets/15/problems/709
#include <stdio.h>
#include <stdlib.h>

void v1(int *a, long int N);
void v2(int *a, long int N);
void v3(int *a, long int N);
void v4(int *a, long int N);

int main() {
    long int i, K;
    scanf("%ld", &K);
    int *a = (int *) malloc(sizeof(int)*K);
    for(i=0; i<K; i++)
        scanf("%d", &a[i]);
    v4(a, K);

    return 0;
}

// 暴力解法
void v1(int *a, long int N) {
    long int i, j, k, max=0, presum=0;
    for(i=0; i<N; i++)
        for(j=i; j<N; j++) {
            presum = 0;
            for(k=i; k<=j; k++)
                presum += a[k];
            if(presum>max) max = presum;
        }

    printf("%d\n", max);
}

void v2(int *a, long int N) {
    long int i, j, max=0, pre=0;
    for(i=0; i<N; i++) {
        pre = 0;
        for(j=i; j<N; j++) {
            pre += a[j];
            if(pre>max) max=pre;
        }
    }
    printf("%d\n", max);   
}

void v3(int *a, long int N) {
    long int i, max=0, pre=0;
    for(i=0; i<N; i++) {
        pre += a[i];
        if(pre>max)     max=pre;
        else if(pre<0)  pre = 0;
    }

    printf("%d\n", max);
}

// 返回3个整数中的最大值
int Max3(long int A, long int B, long int C) { 
    return A > B ? A > C ? A : C : B > C ? B : C;
}

long int v4_helper(int *a, long int left, long int right) {
    long int maxl, prel, maxr, prer;
    long int maxbl, maxbr;
    long i, mid;

    if(left == right) {
        if(a[left]>0)   return a[left];
        else            return 0;
    }

    mid = (left+right)/2;
    maxl = v4_helper(a, left, mid);
    maxr = v4_helper(a, mid+1, right);

    prel = prer = maxbl = maxbr = 0;
    // 从中间求两侧的最值
    for(i=mid; i>=left; i--) {
        prel += a[i];
        if(prel>maxbl) maxbl = prel;
    }
    for(i=mid+1; i<=right; i++) {
        prer += a[i];
        if(prer>maxbr) maxbr = prer;
    }

    return Max3(maxl, maxr, maxbl+maxbr);
}

void v4(int *a, long int N) {
    long int ret = v4_helper(a, 0, N-1);
    printf("%ld\n", ret);
}