// https://pintia.cn/problem-sets/14/problems/791

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x, y;
    cin>>x;

    if(x<=15)
        y = 4*x/3;
    else
        y = 2.5*x - 17.5;

    cout<<fixed<<setprecision(2)<<y<<endl;

    return 0;
}