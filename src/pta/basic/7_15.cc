// https://pintia.cn/problem-sets/14/problems/795

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double delta, k, up, down, sum=0.0;
    cin>>delta;

    // int up, down, n=1;
    int n = 0;
    up = 1;
    down = 2*n+1;
    k = 1;
    while(k>=delta) {
        sum += k;
        n++;
        up*=n;
        down*=(2*n+1);
        k = up/down;
        // cout<<"k is "<<k<<" n is "<<n<<"sum is "<< sum<<endl;
    }
    // 题目理解，“直到最后一项的值小于给定阈值”
    // 所以要加上最后一个k
    sum += k;

    cout<<fixed<<setprecision(6)<<2*sum<<endl;
    return 0;
}