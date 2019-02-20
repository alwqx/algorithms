// https://pintia.cn/problem-sets/14/problems/792

#include <iostream>
using namespace std;

int main() {
    int a, b, ret;
    char op;

    cin>>a>>op>>b;
    if(op == '+')
        ret = a+b;
    else if(op == '-')
        ret = a-b;
    else if(op == '*')
        ret = a*b;
    else if(op == '/')
        ret = a/b;
    else if(op == '%')
        ret = a%b;
    else
    {
        cout<<"ERROR"<<endl;
        return 0;
    }
    
    cout<<ret<<endl;
    return 0;
}