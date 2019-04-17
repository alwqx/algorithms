/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (54.65%)
 * Total Accepted:    39.9K
 * Total Submissions: 72.5K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */
// 超时
class SolutionV1 {
public:
    int maxArea(vector<int>& height) {
        int *dp;
        dp = new int[height.size()];
        dp[0] = 0;
        dp[1] = min(height[0], height[1]);

        int i, j, n;
        for(i=2; i<height.size(); i++) {
            n = dp[i-1];
            for(j=0; j<i; j++) {
                int mhight = min(height[i], height[j]);
                n = max(n, mhight*(i-j));
            }
            dp[i] = n;
        }

        return dp[height.size()-1];
    }
};

// 超时
class SolutionV2 {
public:
    int maxArea(vector<int>& height) {
        int ret = 0;
        int i, j;
        for(i=0; i<height.size()-1; i++) {
            for(j=i+1; j<height.size(); j++)
                ret = max(ret, (j-i)*min(height[i], height[j]));
        }

        return ret;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret=0, low=0, high=height.size()-1;
        while(low<high) {
            ret = max(ret, (high-low)*min(height[low], height[high]));
            if(height[low]<height[high]) low++;
            else high--;
        }

        return ret;
    }
};

/*
# 思路分析
## 法一
使用动态规划做
1. dp[len]数组，dp[i]表示数组中前i个数能存储的最大容量
2. i = i+1时，对前i个数遍历，求与i+1组成的最大容量
3. 循环len次可求结果

问题：O(n*n)，第48个案例超时

## 法二
该思路和法一一样，只不过没有使用动态规划的思路
直接遍历数组，求最大值

时间复杂度 O(n*n)
空间复杂度 O(1)

## 法三
双指针法，参考题解
类似于从两边向中间逼近
*/
