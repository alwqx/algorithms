#include <map>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v;
    int i, type, value, sum;
    while(n--) {
        scanf("%d %d", &type, &value);

        if(type == 1) v.push_back(value);
        else {
            for(auto it=v.begin(); it!=v.end(); ++it)
                if(*it == value) {v.erase(it); break;}
        }

        if(v.size()<3) printf("No\n");
        else {
            sort(v.begin(), v.end());
            sum = 0;
            for(i=0; i<v.size()-1; i++) sum += v[i];
            if(sum>v[i]) printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}