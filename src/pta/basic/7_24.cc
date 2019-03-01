// https://pintia.cn/problem-sets/14/problems/804

#include <iostream>

using namespace std;

int find(int a, int b) {
    int c;
    while(b!=0) {
        c = a%b;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    int up, down;
    char mid;
    cin>>up>>mid>>down;

    if(up == down)
        cout<<"1/1";
    else {
        int c = find(up, down);
        cout<<up/c<<"/"<<down/c;
    }

    return 0;
}