#include <stdio.h>

// https://pintia.cn/problem-sets/14/problems/742
void Print_Factorial (const int N);

int main()
{
    int N;
	
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}

// refer https://blog.csdn.net/lisp1995/article/details/52403507
void Print_Factorial(const int N) {
    if(N<0) {
        printf("Invalid input");
        return;
    }

    if(N == 0) {
        printf("%d", 1);
        return;
    }

    int a[20001], i, j, digit=1;
    a[0] = 1;
    for(i=2; i<=N; i++) {
        int sum = 0;
        for(j=0; j<digit; j++) {
            sum += a[j]*i;
            a[j] = sum%10;
            sum /= 10;
        }
        while(sum) {
            a[digit] = sum%10;
            sum /= 10;
            digit++;
        }
    }

    // print
    for(i=digit-1; i>=0; i--)
        printf("%d", a[i]);
}