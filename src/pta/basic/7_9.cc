// https://pintia.cn/problem-sets/14/problems/789

#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;

    if(a==b)
        cout<<"C"<<endl;
    else if(b==c)
        cout<<"A"<<endl;
    else
        cout<<"B"<<endl;

    return 0;
}