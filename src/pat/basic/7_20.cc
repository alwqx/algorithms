// https://pintia.cn/problem-sets/14/problems/800

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin>>N;

    int i, j;
    for(i=1; i<=N; i++) {
        for(j=1; j<=i; j++) {
            cout<<j<<"*"<<i<<"=";
            cout<<fixed<<setiosflags(ios::left)<<setw(4)<<i*j;
        }
        cout<<endl;
    }
    return 0;
}