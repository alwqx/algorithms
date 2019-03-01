// https://pintia.cn/problem-sets/14/problems/799

#include <iostream>
using namespace std;

// O(N*logN)
int main() {
    int y, f, n, ret, found=1;
    cin>>n;

    int mid, low, high;
    for(y=0; y<100; y++) {
        if(found == 0) break;
        low=0; high=100;
        while(low<=high) {
            mid = (low+high)/2;
            ret = 98*mid-n;
            if(199*y<ret)
                high=high-1;
            else if(199*y>ret)
                low = mid+1;
            else{
                found = 0;
                cout<<y<<"."<<mid<<endl;
                break;
            }
        }
    }

    if(found == 1)
        cout<<"No Solution";
    return 0;
}

/*
O(N*N)
int main() {
    int y, f, n, ret, found=1, i=0;
    cin>>n;
    for(f=0; f<100; f++) {
        if(found == 0) break;
        for(y=0; y<100; y++) {
            if(98*f-199*y == n) {
                found = 0;
                cout<<y<<"."<<f<<endl;
                break;
            }
        }
    }

    if(found == 1)
        cout<<"No Solution";
    return 0;
}
*/