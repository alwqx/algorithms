// https://pintia.cn/problem-sets/994805260223102976/problems

#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct node {
    string No;
    int De;
    int Cai;
};

int cmp(node a, node b) {
    if(a.De+a.Cai != b.De+b.Cai)
        return (a.De+a.Cai)>(b.De+b.Cai);
    else
        if(a.De != b.De)    return a.De>b.De;
        else                return a.No<b.No;
}

int main() {
    long int i, N;
    int L, H;
    scanf("%ld %d %d", &N, &L, &H);
    vector<node> v1, v2, v3, v4;

    long int cnt = 0;
    for(i=0; i<N; i++) {
        node ss;
        cin>>ss.No;
        scanf("%d %d", &ss.De, &ss.Cai);
        if(ss.De>=H && ss.Cai>=H) {
            v1.push_back(ss);
            cnt++;
        } else if (ss.De>=H && ss.Cai>=L && ss.Cai<H) {
            v2.push_back(ss);
            cnt++;
        } else if (ss.Cai>=L&&ss.Cai<H&&ss.De>=L&&ss.De<H&&ss.De>=ss.Cai) {
            v3.push_back(ss);
            cnt++;
        } else if (ss.De>=L && ss.Cai>=L) {
            v4.push_back(ss);
            cnt++;
        }
    }

    sort(v1.begin(), v1.end(), cmp);
    sort(v2.begin(), v2.end(), cmp);
    sort(v3.begin(), v3.end(), cmp);
    sort(v4.begin(), v4.end(), cmp);

    printf("%ld\n", cnt);
    for(i=0; i<v1.size(); i++) {cout<<v1[i].No;printf(" %d %d\n", v1[i].De, v1[i].Cai);}
    for(i=0; i<v2.size(); i++) {cout<<v2[i].No;printf(" %d %d\n", v2[i].De, v2[i].Cai);}
    for(i=0; i<v3.size(); i++) {cout<<v3[i].No;printf(" %d %d\n", v3[i].De, v3[i].Cai);}
    for(i=0; i<v4.size(); i++) {cout<<v4[i].No;printf(" %d %d\n", v4[i].De, v4[i].Cai);}

    return 0;
}