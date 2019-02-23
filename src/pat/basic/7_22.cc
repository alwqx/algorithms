// https://pintia.cn/problem-sets/14/problems/802

#include <iostream>

using namespace std;

int main() {
    int i, t;
    cin>>t;

    int rabbit=0, tortoise=0, flag=0;
    for(i=0; i<t; i++) {
        if(i%10==0 && rabbit>tortoise && flag==0)
            flag=30;
        if(flag==0)
            rabbit += 9;
        else
            flag--;
        tortoise += 3;
    }

    if(tortoise > rabbit)
        cout<<"@_@ "<<tortoise;
    else if(tortoise < rabbit)
        cout<<"^_^ "<<rabbit;
    else
        cout<<"-_- "<<rabbit;
    return 0;
}

/*
int main() {
    int T, sr, st, d;
    cin>>T;

    int t = T%90;
    int delta = T/90;
    if(t>0&&t<30 || t>45&&t<60) {
        cout<<"^_^ ";
        if(t<=10 && t>0)
            d = t*9 + 270*delta;
        else if(t>10 && t<30)
            d = 90 + 270*delta;
        else if(t>45 && t<50)
            d = 90 + 9*(t-40) + 270*delta;
        else if(t>=50 && t<60)
            d = 90 +90 + 270*delta;
        cout<<d<<endl;
    } else if(t==0 || t==30 || t==45 || t==60 || t==90)
        cout<<"-_- "<<T*3<<endl;
    else
        cout<<"@_@ "<<T*3<<endl;

    return 0;
}*/