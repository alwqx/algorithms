// https://pintia.cn/problem-sets/14/problems/798

#include <iostream>
#include <iomanip>
#define DELTA 1e-5

using namespace std;

int f(double a3, double a2, double a1, double a0, double x) {
    double ret = a3*x*x*x + a2*x*x + a1*x +a0;
    if(ret > 0)         return 1;
    else if(ret == 0)   return 0;
    else                return -1;
}

int main() {
    double a3, a2, a1, a0;
    double a, b, mid;
    cin>>a3>>a2>>a1>>a0;
    cin>>a>>b;

    int fa, fb, ret;
    fa = f(a3, a2, a1, a0, a);
    fb = f(a3, a2, a1, a0, b);
    mid = (a+b)/2;
    ret = f(a3, a2, a1, a0, mid);

    while(b-a>DELTA) {
        if(ret == fa)
            a = mid;
        else if(ret == fb)
            b = mid;
        else if(ret<=DELTA)
            break;
        mid = (a+b)/2;
        ret = f(a3, a2, a1, a0, mid);
    }

    cout<<fixed<<setprecision(2)<<mid;
    return 0;
}