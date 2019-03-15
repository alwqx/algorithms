/*
王道考研机试指南 p81

进制转换
*/
#include <stdio.h>
#include <vector>

using namespace std;

void v1();
void v2();

void jinzhi(int a, int k) {
    vector<int> v;
    while(a) {
        v.push_back(a%k);
        a /= k;
    }

    int i;
    for(i=v.size()-1; i>=0; i--)
        printf("%d", v[i]);
    putchar('\n');
}

int main() {
    // v1();
    v2();

    return 0;
}

void v1() {
    int a, b, m;
    while(scanf("%d", &m) != EOF && m!=0) {
        scanf("%d %d", &a, &b);
        jinzhi(a+b, m);
    }
}

void v2() {
    long long a, b;
    int i, m;
    while(scanf("%d", &m) != EOF) {
        if(!m) break;
        scanf("%lld %lld", &a, &b);
        a = a+b;
        int ans[50], size=0;
        do{
            ans[size++] = a%m;
            a /= m;
        } while(a);

        for(i=size-1; i>=0; i--)
            printf("%d", ans[i]);
        putchar('\n');
    }
}