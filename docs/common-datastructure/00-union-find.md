# 并查集

[oi-witi-并查集](https://oi-wiki.org/ds/dsu/)

是一种树型结构，用于处理不相交集的合并与查询问题，定义了两个接口：

- find(x)，查询 x 所属子集
- union(x, y)，将两个子集合并成同一个集合

UF 有两个优化点：

1. union 操作中`按秩合并`，将更小的树连接到更大的树上
2. find 查询时路径压缩，是一种查找时`扁平化树结构`的方法

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

        // p 的节点数比 q 多
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

# [399. 除法求值](https://leetcode-cn.com/problems/evaluate-division/)

我认为这个问题非常经典，而且特别实用，学会这个算法在生活中真的有用武之地。下面的代码参考自 [C++ 带权值的并查集](https://leetcode-cn.com/problems/evaluate-division/solution/c-dai-quan-zhi-de-bing-cha-ji-by-wen-zhong-qiu-she/)，这里的代码是非常好理解的。关键是实际编写中还是要看一会儿才能理解。

在 myUnion(string a, string b) 方法中，将 a 和 b 放在同一个树上。带路径压缩的方法参考 [并查集+路径压缩](https://leetcode-cn.com/problems/evaluate-division/solution/bing-cha-ji-lu-jing-ya-suo-by-bueryt/)。

```cpp
class Solution {
private:
    unordered_map<string, string> parent;
    unordered_map<string, double> weight; // 存储当前节点值/父节点的结果
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // 初始化并查集
        int i;
        string a, b;
        for(i=0; i<equations.size(); i++) {
            a = equations[i][0];
            b = equations[i][1];

            if(parent.find(a) == parent.end()) {
                parent[a] = a;
                weight[a] = 1.0;
            }
            if(parent.find(b) == parent.end()) {
                parent[b] = b;
                weight[b] = 1.0;
            }

            // 因为输入的 equations 暗含了 a/b=x 这个关系，所以函数中人为指定了 a、b 间的方向
            myUnion(a, b, values[i]);
        }

        // 查
        vector<double> ans;
        pair<string, double> pa, pb;
        for(auto &q:queries) {
            a = q[0];
            b = q[1];
            pa = myFind(a);
            pb = myFind(b);

            // 输入的值可能不在并查集中
            if(pa.first!=pb.first || pa.first=="" || pb.first=="") {
                ans.push_back(-1.0);
            } else {
                ans.push_back(pa.second/pb.second);
            }
        }

        return ans;
    }

    // 返回 root 以及节点/root 的值，
    // 带路径压缩
    pair<string, double> myFind(string a) {
        if(parent.find(a) == parent.end()) return {"", -1.0};
        if(parent[a] == a) return {a, 1.0};

        auto t = myFind(parent[a]);
        parent[a] = t.first;
        weight[a] *= t.second;

        return {t.first, weight[a]};
    }

    /*
    // 不带路径压缩
    pair<string, double> myFind(string a) {
        if(parent.find(a) == parent.end())
            return {"", -1.0};

        double res = 1.0;
        while(a != parent[a]) {
            res *= weight[a]; // res *= a/parent
            a = parent[a];
        }

        return {a, res};
    }
    */

    // a_b 表示 a/b 的结果
    void myUnion(string a, string b, double a_b) {
        pair<string, double> pa = myFind(a);
        pair<string, double> pb = myFind(b);

        if(pa.first=="" || pb.first=="") return;
        if(pa.first == pb.first) return;

        // 把 a 的父节点指向 b 的父节点
        parent[pa.first] = pb.first;
        // weight[a] = a_b * pb.second;
        // 更新权值，没看懂。.. 自己的理解是上面的方法
        weight[pa.first] = 1.0 / pa.second * a_b * pb.second;
    }
};
```

[BaymaxHWY](https://leetcode-cn.com/problems/evaluate-division/solution/san-chong-jie-fa-by-baymaxhwy/) 老哥的方法更多，适合拓展思路以及学习，笔者觉得需要消化下，慢慢来~
