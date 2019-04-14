#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct BigNum {
    int num[50];
    int size;

    void init() {
        size = 0;
        int i;
        for(i=0; i<50; i++) num[i] = 0;
    }

    void set(string s) {
        init();
        int i;
        for(i=0; i<s.size(); i++) num[size++] = s[i]-'0';
    }

    void output() {
        int i;
        for(i=size-1; i>=0; i--) printf("%d", num[i]);
        printf("\n");
    }

    BigNum operator + (BigNum &B) {
        BigNum ret;
        ret.init();
        int minv=min(size, B.size);

        int i, sum, carry=0;
        for(i=0; i<minv; i++) {
            sum = carry + num[i] + B.num[i];
            ret.num[ret.size++] = sum%10;
            carry = sum/10;
        }
        for(; i<size; i++) {
            sum = carry + num[i];
            ret.num[ret.size++] = sum%10;
            carry = sum/10;
        }
        for(; i<B.size; i++) {
            sum = carry + B.num[i];
            ret.num[ret.size++] = sum%10;
            carry = sum/10;
        }

        return ret;
    }

    BigNum operator | (BigNum &B) {
        BigNum ret;
        ret.init();
        int minv=min(size, B.size);

        int i;
        for(i=0; i<minv; i++) ret.num[ret.size++] = num[i]|B.num[i];
        for(; i<size; i++) ret.num[ret.size++] = num[i]|0;
        for(; i<B.size; i++) ret.num[ret.size++] = 0|B.num[i];
        
        return ret;
    }

    bool operator < (BigNum &B) {
        if(size == B.size) {
            int i;
            for(i=size-1; i>=0; i--)
                if(num[i] >= B.num[i]) return false;
            return true;
        }

        return size<B.size;
    }

    bool operator == (BigNum &B) {
        if(size == B.size) {
            int i;
            for(i=0; i<size; i++)
                if(num[i] != B.num[i]) return false;
            return true;
        }

        return false;
    }
};

int main() {
    string a, b;
    cin>>a>>b;
    BigNum x, k;
    x.set(a); k.set(b);

    BigNum y, n, c;
    y.set("1"); n.set("0"); c.set("1");

    while(n<k) {
        BigNum t = x|y;
        if(x+y == t) n = n+c;
        y = y+c;
    }
    y.output();

    return 0;
} 