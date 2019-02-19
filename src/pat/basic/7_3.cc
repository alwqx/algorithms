// https://pintia.cn/problem-sets/14/problems/783

#include <iostream>
using namespace std;

int main() {
    int i, sum, token[3];
    cin>>sum;

    for(i=0; i<3; i++) {
        token[i] = sum%10;
        sum /= 10;
    }
    
    // if(token[2] == 0) {
    //     if(token[1] == 0)
    //         sum = token[0];
    //     else
    //     {
    //         sum = 100*token[0] + 10*token[1];
    //     }
    // } else {
    //     sum = 100*token[0] + 10*token[1] + token[2];
    // }
    sum=0;
    for(i=0; i<3; i++) {
        if(token[i] == 0) continue;
        sum = sum*10 + token[i];
    }

    cout<<sum<<endl;

    return 0;
}