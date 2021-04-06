# Algorithms
[![Build Status](https://travis-ci.org/adolphlwq/algorithms.svg?branch=master)](https://travis-ci.org/adolphlwq/algorithms)

<p align="center">
  <a href="https://adolphlwq.xyz/algorithms" target="_blank">
    <img src="https://i.loli.net/2019/02/09/5c5e25acd3469.png" width="700px">
    <br>
    Online Website
  </a>
</p>

<p align="center">Algorithms and Data Structures Distilled with code implemented by multiple languages.</p>

## Implements
| Algorithms  |           C           |         Java          |        Python         |        Golang         |
| :---------: | :-------------------: | :-------------------: | :-------------------: | :-------------------: |
|    Array    |  :heavy_check_mark:   | :black_square_button: | :black_square_button: | :black_square_button: |
|  Link List  |  :heavy_check_mark:   | :black_square_button: | :black_square_button: | :black_square_button: |
|    Stack    |  :heavy_check_mark:   |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|    Queue    |  :heavy_check_mark:   |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|    Tree     | :black_square_button: |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|    Graph    | :black_square_button: |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|   Search    |  :heavy_check_mark:   |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|    Sort     | :black_square_button: |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
|    Hash     |  :heavy_check_mark:   |  :heavy_check_mark:   | :black_square_button: | :black_square_button: |
| Compression | :black_square_button: | :black_square_button: | :black_square_button: | :black_square_button: |

## Getting Involved
- [Document](https://adolphlwq.xyz/algorithms): Dive into details.
- [GitHub Issues](https://github.com/adolphlwq/algorithms/issues): For reporting bugs and feature algorithms.
- [Pull Requests](https://github.com/adolphlwq/algorithms/pulls): For submitting code contributions.

## Reference
- [Learn-Algorithms](https://github.com/nonstriater/Learn-Algorithms)
- [Princeton University Algorithms](/courses/README.md)
- [algs4 source code and api](http://algs4.cs.princeton.edu/code/index.php)
- [Algs in C](https://github.com/TheAlgorithms/C)
- [Algs in Python](https://github.com/keon/algorithms)
- [visualgo](https://visualgo.net/zh)
- [algorithm-visualizer](https://algorithm-visualizer.org/)


```cpp
class Solution {
public:
    /*
    给你2个整数n和k，返回用1-k中的数组成n的数量
    比如n=3, k=2，返回2
    [
        [1,1,1],
        [1,2]
    ]
    */
    int mogen(int n, int k) {
        int cnt=0, sum=0, pos=1;
        vector<int> tmp;
        vector<vector<int>> res;
        dfs(n, k, pos, sum, cnt, res, tmp);

        // print anster
        cout<<"cnt: "<<cnt<<" size: "<<res.size()<<endl;
        // for(int i=0; i<res.size(); i++) {
        //     tmp = res[i];
        //     for(int n:tmp) cout<<n<<" ";
        //     cout<<endl;
        // }
        return cnt;
    }

    void dfs(int n, int k, int pos, int sum, int& cnt, vector<vector<int>>& res, vector<int>& tmp) {
        if(pos>k || sum>n) return;
        if(sum == n) {
            cnt++;
            // res.push_back(tmp);
            return;
        }

        // sum < n
        int i;
        for(i=pos; i<=k && i+sum<=n; i++) {
            tmp.push_back(i);
            dfs(n, k, i, sum+i, cnt, res, tmp);
            tmp.pop_back();
        }
    }

    int numDecodings(string s) {
        mogen(1000, 13);
        return 0;
    }
};
```