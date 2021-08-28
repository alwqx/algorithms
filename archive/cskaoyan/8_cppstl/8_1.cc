/*
王道考研机试指南 p216

C++ STL 字符串处理
*/
#include <iostream>
#include <string>
#include <ctype.h>
#include <cstdio>

using namespace std;

int main() {
    int i, t;
    char s[101];
    scanf("%s", s); // get short string
    string a = s;
    for(i=0; i<a.size(); i++) a[i] = tolower(a[i]);

    while(scanf("%s", s) != EOF) {
        string b = s;
        string c = b;
        for(i=0; i<b.size(); i++) b[i] = tolower(b[i]);

        t = b.find(a, 0);
        while(t != string::npos) {
            c.erase(t, a.size());
            b.erase(t, a.size());
            t = b.find(a, 0);
        }

        t = c.find(' ', 0);
        while(t != string::npos) {
            c.erase(t, 1);
            t = c.find(' ', 0);
        }

        cout<<c<<endl;
    }

    return 0;
}