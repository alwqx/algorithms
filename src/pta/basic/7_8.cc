// https://pintia.cn/problem-sets/14/problems/788

#include <iostream>
using namespace std;

int main() {
    int v;
    cin>>v;

    if(v>60)
        cout<<"Speed: "<<v<<" - Speeding"<<endl;
    else
        cout<<"Speed: "<<v<<" - OK"<<endl;

    return 0;
}