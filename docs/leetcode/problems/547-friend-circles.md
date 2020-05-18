# 547. 朋友圈
## 图的连通性问题
为什么visited数组是一维的？因为朋友关系具有对称性，A和B互为朋友，只需要一个维度记录就可以了。

DFS
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        int i, ans = 0;
        vector<int> visited(size, 0);

        for(i=0; i<size; i++) {
            if(visited[i] == 0) {
                dfs(M, visited, i);
                ans++;
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& M, vector<int>& visited, int i) {
        int j;
        for(j=0; j<M.size(); j++) {
            if(M[i][j]==1 && visited[j]==0) {
                visited[j] = 1;
                dfs(M, visited, j);
            }
        }
    }
}
```

BFS
```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size = M.size();
        int i, j, ans=0;
        vector<int> visited(size, 0);
        queue<int> q;
        
        for(i=0; i<size; i++) {
            if(visited[i] == 0) {
                q.push(i);
                while(!q.empty()) {
                    int s = q.front();
                    q.pop();
                    visited[s] = 1;
                    
                    for(j=0; j<size; j++) {
                        if(M[s][j]==1 && visited[j]==0) {
                            q.push(j);
                        }
                    }
                }

                ans++;
            }
        }

        return ans;
    }
}
```

## 并查集
```cpp
class Solution {
public:
    vector<int> uf;

    int find(int x) {
        if(x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }

    int findCircleNum(vector<vector<int>>& M) {
        int i, j, size=M.size();
        for(i=0; i<size; i++) uf.push_back(i);
        int ans = size;

        for(i=0; i<size; i++) {
            for(j=0; j<i; j++) {
                if(M[i][j] == 0) continue;
                int x = find(i);
                int y = find(j);
                if(x != y) {
                    uf[x] = y;
                    ans--;
                }
            }
        }

        return ans;
    }
}
```

UF放在类中专门实现
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

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int i, j, size = M.size();
        UF* uf = new UF(size);

        for(i=0; i<size; i++) {
            for(j=0; j<i; j++) {
                if(M[i][j] == 0) continue;
                uf->uunion(i, j);
            }
        }

        return uf->count();
    }
};
```

# 参考
- [LeetCode官方题解](https://leetcode-cn.com/problems/friend-circles/solution/peng-you-quan-by-leetcode/)
- [LeetCode labuladong题解](https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/)