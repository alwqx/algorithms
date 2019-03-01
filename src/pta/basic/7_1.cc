// 7.1 https://pintia.cn/problem-sets/14/problems/781

#include <iostream>
using namespace std;

#define M 30.48
int main() {
    int foot, inch, cm;
    double tmp;
    cin>>cm;

    foot = cm/M;
    tmp = cm/M - foot;
    inch = tmp*12;

    cout<<foot<<" "<<inch<<endl;

    return 0;
}