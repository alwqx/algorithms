# 并查集

```cpp
class UF {
private:
    vector<int> size;
    vector<int> group;
    int cnt;

public:
    UF(int n) {
        cnt = n;
        for(int i=0; i<n; i++) {
            size.push_back(1);
            group.push_back(i);
        }
    }

    void uunion(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq) return;

        if(size[rootp] > size[rootq]) {
            group[rootq] = rootp;
            size[rootp] += size[rootq];
        } else {
            group[rootp] = rootq;
            size[rootq] += size[rootp];
        }

        cnt--;
    }

    int find(int x) {
        while(x != group[x]) {
            group[x] = group[group[x]];
            x = group[x];
        }

        return x;
    }

    int count() {
        return cnt;
    }
};
```