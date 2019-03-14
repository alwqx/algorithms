// https://eoj.i64d.com/problem/2572/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(long a, long b) {
    return a<b;
}

int main() {
    long i, n, t;
    vector<long> v;
    cin>>n;
    for(i=0; i<n; i++) {
        cin>>t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp);

    int j, k, m;
    cin>>k;
    for(j=0; j<k; j++) {
        cin>>m;
        cout<<v[m-1]<<endl;
    }
    
    return 0;
}