/*
hello world: 往年原题
*/
#include <stdio.h>
#include <string.h>

#define DEBUG 0

char str[10001];
int num[1000];

void getss() {
    int i = 0;
    char c;
    while((c=getchar()) != '\n')
        str[i++] = c;
    str[i] = '\0';
}

int main() {
    int i, n, t;
    scanf("%d", &t);

    int k, line, single_len, snum, flag, sum;
    while(t--) {
        scanf("%d", &n);
        getchar();
        getss();

        i = 0; k = 0; snum = 0;
        while(i<strlen(str)) {
            if(str[i]=='.' || str[i]=='!' || str[i]=='?') {
                snum++;
                num[k++] = snum;
                snum = 0;
                i += 2; // jump space
            } else {
                i++;
                snum++;
            }
        }

        // judge if impossible
        flag = 1;
        for(i=0; i<k; i++)
            if(num[i] > n) {
                flag = 0;
                break;
            }
        if(!flag) printf("Impossible\n");
        else {
            sum = 0; line = 1;
            for(i=0; i<k; i++) {
                if(sum + num[i] <= n) sum += num[i];
                else {
                    line++;
                    sum = num[i];
                }
            }

            printf("%d\n", line);
        }
    }

    return 0;
}