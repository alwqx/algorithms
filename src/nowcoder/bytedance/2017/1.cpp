// https://www.nowcoder.com/questionTerminal/4bba9f2ab638483093e34377dd9b3e91
#include <stdio.h>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<char, long long> a, pair<char, long long> b) {
    return a.second>b.second;
}

int main() {
    int i, n;
    long long b;
    unsigned long long ret;
    map<char, long long> m; // map char and weight
    set<char> h;            // store head char
    string s;
    while(cin>>n) {
        m.clear();
        while(n--) {
            cin>>s;
            b = 1;
            for(i=s.size()-1; i>=0; i--) {
                m[s[i]] += b;
                b *= 10;
            }
            h.insert(s[0]);
        }

        vector<pair<char, long long>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        // 如果默认值是0，可以不删除最小字符
        // i = v.size()-1;
        // 所有字母出现时，找到没有出现在首字母，且权值最小的字母，题设指出必存在不再首字母的字符
        // while(v.size()==10 && i>=0 && h.find((v[i]).first)!=h.end()) i--;

        ret = 0;
        b = 9;
        for(i=0; i<v.size(); i++) {
            ret = ret + b*v[i].second;
            b--;
        }

        cout<<ret<<endl;
    }

    return 0;
}

/*
思路分析：
自己第一次做的时候没有想到如何确定字母和权值间的映射关系，确保结果最大。
比如ABC BCA两个字符串，A和B哪个是9、哪个是8呢？

看了上面的题解后我理解了，这其实涉及到数的表示和进制以及权值。这里默认是10进制，A B C这样的字母相当于“数码”，也就是0 1 2 ... 9
只不过需要用户根据题目条件“总和最大”来确定具体A B C是哪些数码

解题思路是计算每个字符对应的数码和（权值和），最大的给予9,依次递减，然后求和
*/