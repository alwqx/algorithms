# 图问题汇总
图的问题涉及求最大面积、单词搜索等，可以使用dfs配合回溯来做，也可以使用DP，关键看题目特点。

图问题常用思考框架：
- 拓扑排序
- 入度、出度
- 遍历：DFS/BFS
- 并查集
- 最短路径算法
  - 迪杰斯特拉
  - flood
  - ...

# [547. 省份数量-原朋友圈](https://leetcode-cn.com/problems/number-of-provinces/)
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

## 参考
- [LeetCode官方题解](https://leetcode-cn.com/problems/friend-circles/solution/peng-you-quan-by-leetcode/)
- [LeetCode labuladong题解](https://leetcode-cn.com/problems/friend-circles/solution/union-find-suan-fa-xiang-jie-by-labuladong/)


# [787. K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/)
DP的思路自己没想到，迪杰斯特拉算法要熟悉！

# [1267. 统计参与通信的服务器](https://leetcode-cn.com/problems/count-servers-that-communicate/)
自己尝试使用并查集做，问题出在声明的数组长度m*n，但是计算索引i*m+j有时候会溢出，[我的题解](https://leetcode-cn.com/problems/count-servers-that-communicate/solution/bing-cha-ji-si-lu-zheng-que-dan-shi-dai-3792w/)

# [1162. 地图分析](https://leetcode-cn.com/problems/as-far-from-land-as-possible/)
想清楚dp的表示和含义，自己考虑得没有题解细致：
1. 我想的是一轮dp，同时计算四个方向
2. 我考虑的对角线的值到dp中，看了题解发现不需要，因为上方的值在计算时考虑了两个方向，其中就包含当前值的左上方，0在计算a的时候，a计算了b，相当于0计算了b
```shell
b a 1
1 0 1
```

# [959. 由斜杠划分区域](https://leetcode-cn.com/problems/regions-cut-by-slashes/)
如何将问题抽象成并查集，以及索引的设置和计算是本题的关键。

# [886. 可能的二分法](https://leetcode-cn.com/problems/possible-bipartition/)
下面的代码注释中是我之前的提交，代码有问题所以无法通过，查看了官方题解中的代码，在图的构造上和我的不同，核心代码如下：
```cpp
for(i=0; i<dislikes.size(); i++) {
    /*
    下面的代码是错误的，在实际提交中无法通过
    u = min(dislikes[i][0], dislikes[i][1]);
    v = max(dislikes[i][0], dislikes[i][1]);
    graph[u].push_back(v);
    */

    u = dislikes[i][0];
    v = dislikes[i][1];
    graph[u].push_back(v);
    graph[v].push_back(u);
}
```

上面注释中的代码构造的图不是双向的，比如`1-2`，得到的图如下，这样在dfs过程中容易出问题。
```shell
1: 2
2
```
下面是自己找到的反例，`dislikes=[[1,4], [2,5], [4,5]]`，得到的图是：
```shell
1:4
2:5
3
4:5
5
```
这样从1开始dfs的路径是1-4-5，2-5，这里1-4-5中5的颜色是R，2-5中5的颜色是B，这就冲突了。应该构建双向图，这样从1开始dfs的路径是1-4-1-5-2-4，就不会有后面从2的dfs了。
```shell
1:4
2:5
3
4:1-5
5:2-4
```

源代码
```cpp
class Solution {
private:
    const int W = 0;
    const int R = 1;
    const int B = 2;
    vector<vector<int>> graph;
    vector<int> colors;
    bool res;

    void pp() {
        // print graph
        for(int i=0; i<graph.size(); i++) {
            cout<<i<<":";
            for(int v:graph[i]) {
                cout<<"->"<<v;
            }
            cout<<endl;
        }
        cout<<endl;

        // print colors
        for(int i=0; i<colors.size(); i++) {
            cout<<i<<": "<<colors[i]<<endl;
        }
        cout<<endl;
    }

    void dfs(int u, int c) {

        if(colors[u]!=W) {
            if(colors[u] != c) {
                // pp();
                cout<<"u: "<<u<<" colors[u]: "<<colors[u]<<" c: "<<c<<endl;
                res = false;
            }
            return;
        }

        colors[u] = c;
        int nc = c==R?B:R;
        for(int v:graph[u]) {
            dfs(v, nc);
            if(!res) return;
        }
    }
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        res = true;
        graph.resize(N+1);
        colors.resize(N+1, W);

        int i, u, v;
        for(i=0; i<dislikes.size(); i++) {
            /*
            下面的代码是错误的，在实际提交中无法通过
            u = min(dislikes[i][0], dislikes[i][1]);
            v = max(dislikes[i][0], dislikes[i][1]);
            graph[u].push_back(v);
            */

            u = dislikes[i][0];
            v = dislikes[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for(i=1; i<=N; i++) {
            if(colors[i] == W) {
                dfs(i, R);
                if(!res) {
                    cout<<"i: "<<i<<endl;
                    return res;
                }
            }
        }
        return res;
    }
};
```

# [802. 找到最终的安全状态](https://leetcode-cn.com/problems/find-eventual-safe-states/)
看的官方题解，自己想思路的时候可以画图辅助理解。

拓扑排序使用队列来做这个方法忘记了，自己用for循环做的，最后一个样例显示超时。

如果题目不理解、没有想到方法的话很难做出来。


# [785. 判断二分图](https://leetcode-cn.com/problems/is-graph-bipartite/)
没有想到方法，看了题解的方法自己没有搞出来bfs的代码。

# [765. 情侣牵手](https://leetcode-cn.com/problems/couples-holding-hands/)
[官方题解](https://leetcode-cn.com/problems/couples-holding-hands/solution/qing-lu-qian-shou-by-leetcode-gl1c/)首先进行理论分析，得到的结论是不管怎么还，最少交换次数以固定的，但是交换的方式可能是多样的。这里不需要求出所有的交换方式，而是要求最少交换次数。理解了这一点，问题就好处理了。

最简单的方法是原地交换，这个解法真的是非常简洁，利用了异或运算，也提醒笔者要复习下逻辑运算。
```cpp
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int cnt = 0;
        int i, j, a, b;
        for(i=0; i<row.size()-1; i+=2) {
            a = row[i];
            b = a^1; // 这里非常精妙
            if(row[i+1] == b) continue;

            for(j=i+1; j<row.size(); j++) {
                if(row[j] == b) {
                    swap(row[i+1], row[j]);
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }
}
```

# [743. 网络延迟时间](https://leetcode-cn.com/problems/network-delay-time/)
图的`单源最短路径问题`，深搜或者迪杰斯特拉算法。图中必须掌握的算法，非常基础的问题。

参考[五种最短路径算法总结](https://leetcode-cn.com/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/)

# [684. 冗余连接](https://leetcode-cn.com/problems/redundant-connection/) && [685. 冗余连接 II](https://leetcode-cn.com/problems/redundant-connection-ii/)
一开始自己的思路是使用节点的度来计算，先根据边计算出每个节点的度，然后从后向前遍历边，判断边的两个端点对应的度，只要degree[u v]>1，则认为该边可以去掉。[实际案例运行过程中报错了](https://leetcode-cn.com/submissions/detail/169504601/)，看来我的方法不是等价的方法。

题解用的方法是并查集，相对来说比较方便好理解，但是不是完整的并查集，而是根据题目要求简化了。

685 是升级版，hard难度，无论冲代码量、数据结构、思维量这三个角度来思考，都是很不错的考察题目。

# [332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)
看题目完全没思路，看题解是欧拉通路，需要好好理解官方题解。

# [310. 最小高度树](https://leetcode-cn.com/problems/minimum-height-trees/)
自己的思路是遍历所有节点，一次算出每个节点为根节点得到的树的高度，然后求出最小高度，将最小高度的根节点加入到返回数组中。

这个思路通过了65/68个样例，后面超时了。然后看了题解的思路，是利用bfs的思路，从外围向里逼近，树的高度最小，对应的根节点越可能在整个图的中心位置。

[这个题解C++】循序渐进的思路，BFS/DFS/拓扑排序](https://leetcode-cn.com/problems/minimum-height-trees/solution/c-xun-xu-jian-jin-de-si-lu-bfsdfstuo-bu-hmk2y/)给出了三种方法，**并且有dfs记忆化剪枝**，多看看。

# [207. 课程表](https://leetcode-cn.com/problems/course-schedule/) && [210. 课程表 II](https://leetcode-cn.com/problems/course-schedule-ii/)
非常经典的题目，判断图中是否有环，自己一开始想用并查集做的，但是没有想出来并查集怎么做。看了题解发现可以使用拓扑排序的方法，通过dfs或者bfs来做。

问题中并没有包含完整的图结构，所以需要自己根据需要来选择图的表示方法，题解使用的是邻接数组的表示方法。


210的思路和207是一样的。

# [133. 克隆图](https://leetcode-cn.com/problems/clone-graph/)
自己的做法相对复杂些，使用三个map存储节点和邻接节点之间的关系，没有官方题解简单（只用了一个map），但是理解起来相对复杂些。

应对了那句话，用思维换代码负载度，思考的多一些，编写的代码就简洁些，但是理解起来要花费更多脑力。

# [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)
第一次做看完题目有点懵，没有思路，看了别人的题解通过的。

第二次看这道题目，大概知道要用dfs，但是具体dfs怎么处理？是否要用visited数组？dfs是否有返回值等自己还不明确，`只知道大致思路，却不清楚如何实现`。

看了第一次的提交记录后，发现dfs返回的是**发现1的数量**，而且通过**将访问过的grid[i][j]置为0**，巧妙地避免引入visited数组，减少了存储空间。

dfs代码
```cpp
class Solution {
    int dfs(vector<vector<int>>& grid, int curi, int curj) {
        int row=grid.size(), col=grid[0].size();
        if(curi<0||curi==row||curj<0||curj==col||grid[curi][curj]==0) return 0;

        grid[curi][curj] = 0;
        int i, nx, ny, res=1;
        int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
        for(i=0; i<4; i++) {
            nx = curi + dir[i][0];
            ny = curj + dir[i][1];
            res += dfs(grid, nx, ny);
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int i, j, ans = 0;
        for(i=0; i<grid.size(); i++) {
            for(j=0; j<grid[0].size(); j++)
                ans = max(ans, dfs(grid, i, j));
        }

        return ans;
    }
};
```

bfs，bfs的特点是使用队列，遇到一个grid[i][j]=1就加入到队列中，然后进行bfs。
```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row=grid.size(), col=grid[0].size();
        int i, j, k, nx, ny, area=0, ans=0;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int, int>> q;
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(grid[i][j]) {
                    q.push(make_pair(i, j));
                    grid[i][j] = 0;
                    area = 1;

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for(k=0; k<4; k++) {
                            nx = x + dir[k][0];
                            ny = y + dir[k][1];
                            if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]) {
                                grid[nx][ny] = 0;
                                q.push(make_pair(nx, ny));
                                area++;
                            }
                        }
                    }

                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};
```

# 200. 岛屿数量
有了695的铺垫，这个题目dfs和bfs思路就相对简单些了。

dfs
```cpp
class Solution {
public:
    void dfs(vector<vector<char>>& grid, int x, int y) {
        int row=grid.size(), col=grid[0].size();
        if(x<0||x==row||y<0||y==col||grid[x][y]=='0') return;

        int i, nx, ny;
        grid[x][y] = '0';
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(i=0; i<4; i++) {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            dfs(grid, nx, ny);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int i, j, ans=0;
        for(i=0; i<grid.size(); i++) {
            for(j=0; j<grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
```

bfs
```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        if(col == 0) return 0;

        int i, j, k, ans=0;
        int nx, ny;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        queue<pair<int, int>> q;
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    q.push(make_pair(i, j));
                    grid[i][j] = '0';
                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for(k=0; k<4; k++) {
                            nx = x + dir[k][0];
                            ny = y + dir[k][1];
                            if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]=='1') {
                                grid[nx][ny] = '0';
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }

                    ans++;
                }
            }
        }

        return ans;
    }
};
```

并查集，**用并查集的关键是把二维的grid映射到一维的数组中**。
```cpp
class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        int i, j, row=grid.size(), col=grid[0].size();
        count = 0;

        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    group.push_back(i*col+j);
                    count++;
                } else group.push_back(-1);
                size.push_back(1);
            }
        }
    }

    int find(int x) {
        while(x != group[x]) {
            group[x] = group[group[x]];
            x = group[x];
        }

        return x;
    }

    void uunion(int x, int y) {
        int rootx=find(x), rooty=find(y);
        if(rootx == rooty) return;

        if(size[rootx] < size[rooty]) {
            group[rootx] = rooty;
            size[rooty] += size[rootx];
        } else {
            group[rooty] = rootx;
            size[rootx] += size[rooty];
        }

        count--;
    }

    int cnt() {
        return count;
    }

private:
    int count;
    vector<int> group, size;
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();

        UnionFind uf(grid);
        int i, j, k, nx, ny;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(grid[i][j] == '1') {
                    grid[i][j] = '0';
                    for(k=0; k<4; k++) {
                        nx = i + dir[k][0];
                        ny = j + dir[k][1];
                        if(nx>=0&&nx<row&&ny>=0&&ny<col&&grid[nx][ny]=='1') {
                            uf.uunion(i*col+j, nx*col+ny);
                        }
                    }
                }
            }
        }

        return uf.cnt();
    }
};
```

# 463. 岛屿的周长
一开始没有透彻理解，`找规律的思路`，假设岛屿数量为n，则周长为n*2+2，其实这个思路是错误的，只能通过50%的案例。

后来发现思路不对，就以dfs入手，当前节点为1(岛屿)，总边长是否增加取决于四周的情况：
1. 四周有越界，则加1
2. 四周没越界，且为0，则加1
3. 然后递归四周，核心代码如下

```cpp
void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    if(x<0 || x==row || y<0 || y==col || visited[x][y] || grid[x][y]==0) return;

    int i, nx, ny;
    visited[x][y] = true;

    // calc bian
    for(i=0; i<4; i++) {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        if(nx<0 || nx>=row || ny<0 || ny>=col) ans++;
        else if(grid[nx][ny] == 0) ans++;
    }

    // digui
    for(i=0; i<4; i++) {
        nx = x + dir[i][0];
        ny = y + dir[i][1];
        dfs(grid, visited, nx, ny);
    }
}
```

然后递归。
```cpp
class Solution {
private:
    int row, col, ans=0;
    int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        if(row == 0) return 0;
        col = grid[0].size();
        if(col == 0) return 0;

        vector<vector<bool>> visited(row, vector<bool>(col, false));

        int i, j, k;
        for(i=0; i<row; i++) {
            for(j=0; j<col; j++) {
                if(grid[i][j]==1 && !visited[i][j]) {
                    dfs(grid, visited, i, j);
                    break;
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
        if(x<0 || x==row || y<0 || y==col || visited[x][y] || grid[x][y]==0) return;

        int i, nx, ny;
        visited[x][y] = true;

        // calc bian
        for(i=0; i<4; i++) {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx<0 || nx>=row || ny<0 || ny>=col) ans++;
            else if(grid[nx][ny] == 0) ans++;
        }

        // digui
        for(i=0; i<4; i++) {
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            dfs(grid, visited, nx, ny);
        }
    }
};
```

# [399. 除法求值](https://leetcode-cn.com/problems/evaluate-division/)
我认为这个问题非常经典，而且特别实用，学会这个算法在生活中真的有用武之地。下面的代码参考自[C++ 带权值的并查集](https://leetcode-cn.com/problems/evaluate-division/solution/c-dai-quan-zhi-de-bing-cha-ji-by-wen-zhong-qiu-she/)，这里的代码是非常好理解的。关键是实际编写中还是要看一会儿才能理解。

在myUnion(string a, string b)方法中，将a和b放在同一个树上。带路径压缩的方法参考[并查集+路径压缩](https://leetcode-cn.com/problems/evaluate-division/solution/bing-cha-ji-lu-jing-ya-suo-by-bueryt/)。

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

            // 因为输入的equations暗含了a/b=x这个关系，所以函数中人为指定了a、b间的方向
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

    // 返回root以及节点/root的值，
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

    // a_b表示a/b的结果
    void myUnion(string a, string b, double a_b) {
        pair<string, double> pa = myFind(a);
        pair<string, double> pb = myFind(b);

        if(pa.first=="" || pb.first=="") return;
        if(pa.first == pb.first) return;

        // 把a的父节点指向b的父节点
        parent[pa.first] = pb.first;
        // weight[a] = a_b * pb.second;
        // 更新权值，没看懂...自己的理解是上面的方法
        weight[pa.first] = 1.0 / pa.second * a_b * pb.second;
    }
};
```

[BaymaxHWY](https://leetcode-cn.com/problems/evaluate-division/solution/san-chong-jie-fa-by-baymaxhwy/)老哥的方法更多，适合拓展思路以及学习，笔者觉得需要消化下，慢慢来~