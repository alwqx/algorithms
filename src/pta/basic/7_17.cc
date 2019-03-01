// https://pintia.cn/problem-sets/14/problems/797

#include <iostream>

using namespace std;

int main() {
    int N, U, D;
    cin>>N>>U>>D;

    int N0, delta, t0;
    N0 = N-U; delta = U-D;
    if(N0<0)
        cout<<1;
    else{
        if(N0%delta == 0)
            t0 = N0/delta;
        else
            t0 = N0/delta + 1;
        cout<<(t0*2+1);
    }

    return 0;
}