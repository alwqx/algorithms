// https://pintia.cn/problem-sets/14/problems/786

#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    float f1;
    int i;
    char c;
    float f2;

    cin>>f1;
    cin>>i;
    cin>>c;
    cin>>f2;

    cout<<c<<" "<<i<<" ";
    
    cout<<fixed<<setprecision(2)<<f1<<" "<<f2<<endl;
    return 0;
}