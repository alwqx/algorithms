// https://pintia.cn/problem-sets/14/problems/793

#include <iostream>
using namespace std;

int main() {
    float open, high, low, close;
    cin>>open>>high>>low>>close;

    if(close<open) {
        cout<<"BW-Solid";
    } else if(close==open) {
        cout<<"R-Cross";
    } else {
        cout<<"R-Hollow";
    }
    
    if(low<open && low<close && high>open && high>close) {
        cout<<" with Lower Shadow and Upper Shadow";
        return 0;
    }

    if(low<open && low<close)
        cout<<" with Lower Shadow";

    if(high>open && high>close) 
        cout<<" with Upper Shadow";

    return 0;
}