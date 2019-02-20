// https://pintia.cn/problem-sets/14/problems/790

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int year, hour;
    float sum=0;
    int size=0;

    cin>>year>>hour;
    if(year<5)
        size=30;
    else
        size=50;
    
    if(hour<=40)
        sum = size*hour;
    else
        sum = 40*size + (hour-40)*size*1.5;
    
    cout<<fixed<<setprecision(2)<<sum<<endl;
}