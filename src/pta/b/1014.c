// https://pintia.cn/problem-sets/994805260223102976/problems/994805308755394560
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXN 61

char wa[][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    char s1[MAXN], s2[MAXN], s3[MAXN], s4[MAXN];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    scanf("%s", s4);

    int i;
    for(i=0; i<strlen(s1); i++) {
        // if(s1[i]==s2[i] && isupper(s1[i])) {
        if(s1[i]==s2[i] && s1[i]>='A'&&s1[i]<='G') {
            printf("%s ", wa[s1[i]-'A']);
            i++;
            break;
        }
    }
    for(; i<strlen(s1); i++) {
        if(s1[i] == s2[i]) {
            if(isdigit(s1[i])) {
                printf("0%c:", s1[i]);
                break;
            // } else if(isupper(s1[i])) {
            } else if(s1[i]>='A' && s1[i]<='N') {
                printf("%d:", s1[i]-'A'+10);
                break;
            }
        }
    }
    
    for(i=0; i<strlen(s3); i++) {
        if(s3[i]==s4[i] && isalpha(s3[i])) {
            printf("%02d\n", i);
            break;
        }
    }
    
    return 0;
}