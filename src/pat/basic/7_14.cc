// https://pintia.cn/problem-sets/14/problems/794

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i, a, b, sum=0;
    cin>>a>>b;

    for(i=a; i<=b-5; i+=5) {
        sum += i*5 + 10;
        cout<<setiosflags(ios::right)<<setw(5)<<i;
        cout<<setiosflags(ios::right)<<setw(5)<<i+1;
        cout<<setiosflags(ios::right)<<setw(5)<<i+2;
        cout<<setiosflags(ios::right)<<setw(5)<<i+3;
        cout<<setiosflags(ios::right)<<setw(5)<<i+4<<endl;
    }
    for(; i<=b; i++) {
        sum += i;
        cout<<setiosflags(ios::right)<<setw(5)<<i;
    }

    cout<<endl<<"Sum = "<<sum;
    return 0;
}