// https://pintia.cn/problem-sets/14/problems/796

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int i, j, k, a, count=0;
    cin>>a;
    int arr[4] = {a, a+1, a+2, a+3};

    for(i=0; i<4; i++) {
        for(j=0; j<4; j++) {
            for(k=0; k<4; k++) {
                if(i==j || i==k || j==k)
                    continue;
                count++;
                if(count%6==0)
                    cout<<arr[i]<<arr[j]<<arr[k]<<endl;
                else
                    cout<<arr[i]<<arr[j]<<arr[k]<<" ";
            }
        }
    }

    return 0;
}


/*
int main() {
    int n1, n2, n3, n4;
    int a;
    cin>>a;
    n1=a; n2=a+1; n3=a+2; n4=a+3;

    cout<<100*n1+10*n2+n3<<" "<<100*n1+10*n2+n4<<" "<<100*n1+10*n3+n2<<" ";
    cout<<100*n1+10*n3+n4<<" "<<100*n1+10*n4+n2<<" "<<100*n1+10*n4+n3<<endl;

    cout<<100*n2+10*n1+n3<<" "<<100*n2+10*n1+n4<<" "<<100*n2+10*n3+n1<<" ";
    cout<<100*n2+10*n3+n4<<" "<<100*n2+10*n4+n1<<" "<<100*n2+10*n4+n3<<endl;

    cout<<100*n3+10*n1+n2<<" "<<100*n3+10*n1+n4<<" "<<100*n3+10*n2+n1<<" ";
    cout<<100*n3+10*n2+n4<<" "<<100*n3+10*n4+n2<<" "<<100*n3+10*n4+n2<<endl;

    cout<<100*n4+10*n1+n2<<" "<<100*n4+10*n1+n3<<" "<<100*n4+10*n2+n1<<" ";
    cout<<100*n4+10*n2+n3<<" "<<100*n4+10*n3+n1<<" "<<100*n4+10*n3+n2<<endl;

    return 0;
}
*/