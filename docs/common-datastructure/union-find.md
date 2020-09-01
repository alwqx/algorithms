# 并查集
是一种树型结构，用于处理不相交集的合并与查询问题，定义了两个接口：
- find(x)，查询x所属子集
- union(x, y)，将两个子集合并成同一个集合

UF有两个优化点：
1. union操作中`按秩合并`，将更小的树连接到更大的树上
2. find查询时路径压缩，是一种查找时`扁平化树结构`的方法

```cpp
class UF {
private:
    vector<int> rank;
    vector<int> parent;
    int cnt;

public:
    UF(int n) {
        cnt = n;
        for(int i=0; i<n; i++) {
            rank.push_back(1);
            parent.push_back(i);
        }
    }

    void uunion(int p, int q) {
        int rootp = find(p);
        int rootq = find(q);
        if(rootp == rootq) return;

        // p的节点比q多
        if(rank[rootp] > rank[rootq]) {
            parent[rootq] = rootp;
            rank[rootp] += rank[rootq];
        } else {
            parent[rootp] = rootq;
            rank[rootq] += rank[rootp];
        }

        cnt--;
    }

    int find(int x) {
        /*
        // 递归写法
        if(x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
        */
        while(x != parent[x]) {
            parent[x] = parent[parent[x]];
            // 这里进行了“路径压缩”优化
            x = parent[x];
        }

        return x;
    }

    bool connected(int x, int y) {
        // return parent[x] == parent[y];
        return find(x) == find(y);
    }

    int count() {
        return cnt;
    }
};
```

# 参考
- [并查集](https://zh.wikipedia.org/wiki/%E5%B9%B6%E6%9F%A5%E9%9B%86)