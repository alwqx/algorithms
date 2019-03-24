/*
编译器解析，没看懂
*/
#include <stdio.h>

char ex[110];
int indexv;
void ggets() {
    int i=0;
    char c;
    while((c=getchar()) != '\n')
        ex[i++] = c;
    ex[i] = '\0';
}

bool A();
bool B();
bool C();

bool A() {
    if(ex[indexv] == 'x') {
        indexv++;
        while(ex[indexv] == ' ') indexv++;
        return true;
    }

    if(ex[indexv] == '(') {
        indexv++;
        while(ex[indexv] == ' ') indexv++;
        if(B() && ex[indexv]==')') {
            indexv++;
            while(ex[indexv] == ' ') indexv++;
            return true;
        }
    }

    return false;
}

bool B() {
    return A() && C();
}

bool C() {
    while(ex[indexv] == '+') {
        indexv++;
        while(ex[indexv] == ' ') indexv++;
        if(!A()) return false;
    }

    return true;
}

int main() {
    int i, N;
    scanf("%d", &N);
    getchar();
    while(N--) {
        // gets(ex);
        ggets();
        indexv = 0;
        printf("%s\n", A()&&ex[indexv]=='\0'?"Good":"Bad");
    }

    return 0;
}