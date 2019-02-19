// https://pintia.cn/problem-sets/14/problems/782

#include <iostream>
using namespace std;

int main() {
    int tot, mins, sum, hour;
    cin>>tot;
    cin>>mins;

    sum = tot%100;  // mins
    hour = tot/100;
    sum += 60*hour + mins;

    mins = sum%60;
    hour = sum/60;

    tot = hour*100 + mins;

    cout<<tot<<endl;

    return 0;
}