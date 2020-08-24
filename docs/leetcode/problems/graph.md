# 图问题汇总
图的问题涉及求最大面积、单词搜索等，可以使用dfs配合回溯来做，也可以使用DP，关键看题目特点。

## [695. 岛屿的最大面积](https://leetcode-cn.com/problems/max-area-of-island/)
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

## 200. 岛屿数量
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

## 463. 岛屿的周长
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

在myUnion(string a, string b)方法中，将a和b放在同一个树上，

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

            if(pa.first!=pb.first || pa.first=="" || pb.first=="") {
                ans.push_back(-1.0);
            } else {
                ans.push_back(pa.second/pb.second);
            }
        }

        return ans;
    }

    // 返回root以及节点/root的值
    pair<string, double> myFind(string a) {
        if(parent.find(a) == parent.end())
            return {"", -1.0};
        
        double res = 1.0;
        string b = a;
        while(a != parent[a]) {
            res *= weight[a]; // res *= a/parent
            a = parent[a];
        }

        return {a, res};
    }

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