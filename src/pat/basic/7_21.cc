// https://pintia.cn/problem-sets/14/problems/801

#include <iostream>

using namespace std;

int main() {
    int x, y, N, found=1;
    cin>>N;

    if(N<=4) {
        for(x=1; x<N; x++)
            for(y=x; y<=N-x*x; y++){
                if(x*x+y*y == N) {
                    cout<<x<<" "<<y<<endl;
                    found = 0;
                }
            }
    } else {
        for(x=1; x*x<N; x++)
            for(y=x; y<=N-x*x; y++){
                if(x*x + y*y == N) {
                    cout<<x<<" "<<y<<endl;
                    found = 0;
                }
            }
    }

    if(found == 1)
        cout<<"No Solution";
    return 0;
}