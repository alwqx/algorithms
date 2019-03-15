/*
王道考研 p54
*/
#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

char s[220];
int mat[][5] = {
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 1, 1, 0, 0,
    1, 1, 1, 0, 0,
};

stack<int> op;
stack<double> in;

void getop(bool &reto, int &retn, int &i) {
    if(i==0 && op.empty()==true) {
        reto = true;
        retn = 0;
        return;
    }

    if(s[i] == '\0') {
        reto = true;
        retn = 0;
        return;
    }

    if(s[i]>='0' && s[i]<='9')
        reto = false;
    else {
        reto = true;
        switch(s[i]) {
        case '+':
            retn = 1;
            break;
        case '-':
            retn = 2;
            break;
        case '*':
            retn = 3;
            break;
        case '/':
            retn = 4;
            break;
        }

        i += 2;
        return;
    }

    retn = 0;
    for(; s[i]!=' '&&s[i]!='\0'; i++) {
        retn *= 10;
        retn += s[i] - '0';
    }

    if(s[i] == ' ') i++;

    return;
}

int main() {
    cin>>s;

    return 0;
}