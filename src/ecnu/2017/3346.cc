// https://eoj.i64d.com/problem/3346/
#include <iostream>
#include <vector>

using namespace std;

struct point {
    int x;
    int y;
    point(){};
    point(int xx, int yy):x(xx), y(yy) {};
};

vector<point> p;

void v1();
void v2();

int main() {
    // v1();
    v2();

    return 0;
}

void v1() {
    int i, j, n;
    cin>>n;
    int x, y, cnt=0;
    for(i=0; i<n; i++) {
        cin>>x>>y;
        p.push_back(point(x, y));
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++)
            if(p[i].x==p[j].x || p[i].y==p[j].y || abs(p[i].x-p[j].x)==abs(p[i].y-p[j].y))
                cnt++;
    }

    cout<<cnt<<endl;
}

#define ll long long
#define N 100010

void v2() {
    ll i, n;
    ll row[N]={0}, col[N]={0}, diaz[2*N]={0}, diaf[2*N]={0};

    cin>>n;
    ll x, y;
    for(i=0; i<n; i++) {
        cin>>x>>y;
        row[x]++;
        col[y]++;
        diaz[y-x+n]++;
        diaf[x+y]++;
    }

    ll cnt=0;
    for(i=0; i<N; i++) {
        if(row[i]>=2) cnt += row[i]*(row[i]-1)/2;
        if(col[i]>=2) cnt += col[i]*(col[i]-1)/2;
    }

    for(i=1; i<2*N; i++) {
        if(diaz[i]>=2) cnt += diaz[i]*(diaz[i]-1)/2;
        if(diaf[i]>=2) cnt += diaf[i]*(diaf[i]-1)/2;
    }

    cout<<cnt<<endl;
}