// https://eoj.i64d.com/problem/3530/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string a, string b) {
    return a>b;
}

int main() {
    int N;
    scanf("%d", &N);

    int i;
    vector<string> v;
    for(i=0; i<N; i++) {
        string s;
        cin>>s;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), cmp);
    for(i=0; i<N; i++) cout<<v[i];
    cout<<endl;

    return 0;
}