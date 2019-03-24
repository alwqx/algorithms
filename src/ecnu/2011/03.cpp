#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

struct Stu {
    char name[8];
    int score;

    bool operator < (const Stu &B) {
        if(score != B.score) return score<B.score;
        return strcmp(name, B.name) < 0;
    }
};

int main() {
    int t, n, q, i, j, m;
    scanf("%d", &t);
    vector<Stu> vstu;
    while(t--) {
        // clear stu
        vstu.clear();
        // input stu info
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            Stu stu;
            scanf("%s %d", stu.name, &stu.score);
            vstu.push_back(stu);
        }
        sort(vstu.begin(), vstu.end());
        // output
        // for(i=0; i<vstu.size(); i++) printf("%s %d\n", vstu[i].name, vstu[i].score);

        // output
        scanf("%d", &q);
        while(q--) {
            scanf("%d", &m);
            // search
            for(i=0; i<vstu.size(); i++) {
                if(vstu[i].score <= m) continue;
                else break;
            }
            if(i>vstu.size()-1) printf("Impossible\n");
            else printf("%s\n", vstu[i].name);
        }
    }

    return 0;
}