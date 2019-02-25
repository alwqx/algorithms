#include<stdio.h>

int main (void)
{
    int n, initial_n;
    scanf("%d", &n);
    initial_n = n; 
    
    char num[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char token[10] = {0, 0, 'S', 'B', 'Q', 'W', 'S', 'B', 'Q', 'Y'};
    char result[17]={0}; // result init
    
    int i, j=0, last_i=n%10;
    int count = 0;
    while (n > 0) {
        i = n % 10;
        n /= 10;
        count++;

        // 十位或百位上的零
        if (i==0 && (count%4)>1) {
            if (last_i != 0) {// 前一位不是零 
                result[j++] = num[i];    
            }
        }
        // 单位 W
        if (count==5 && i==0 && initial_n<100000000) {
            result[j++] =  token[count];
        }
        // 是不是个位，个位不需要单位，不是个位，加单位
        if (count>1 && i!=0) {    
            result[j++] = token[count];
        }
        if (i != 0) {               
            result[j++] = num[i];
        }

        last_i = i; 
    }
    
    if (initial_n == 0) {       
        result[j++]  = num[i];
    }
    
    for (j=j-1; j>=0; j--) {
        printf("%c", result[j]);
    }
    
    return 0;
}