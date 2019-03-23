#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s[100001];

int conv(string s) {
    int i, ret=0;
    for(i=0; i<s.size(); i++) {
        ret += 10*ret+(s[i]-'0');
    }

    return ret;
}

int cmp(string a, string b) {
    int m = conv(a), n=conv(b);
    return m<n;
}

int main() {
    int i, n;
    cin>>n;
    for(i=0; i<n; i++)
        cin>>s[i];

    sort(s, s+n);
    for(i=0; i<n; i++)
        if(i==0) cout<<s[i];
        else cout<<" "<<s[i];
    cout<<endl;

    sort(s, s+n, cmp);
    for(i=0; i<n; i++)
        if(i==0) cout<<s[i];
        else cout<<" "<<s[i];

    return 0;
}
