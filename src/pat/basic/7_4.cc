// https://pintia.cn/problem-sets/14/problems/784

#include <iostream>
using namespace std;

int main() {
    int dest, token[2];
    cin>>dest;

    token[0] = dest%16;
    token[1] = dest/16;

    cout<<token[1]*10 + token[0]<<endl;
    return 0;
}