/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (42.93%)
 * Total Accepted:    12.5K
 * Total Submissions: 29K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 * 
 * 
 * 
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 感谢
 * Marcos 贡献此图。
 * 
 * 示例:
 * 
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 * 
 */
class Solution {
public:
    int trap(vector<int>& height) {
        int i, n = height.size();
        vector<int> left(n), right(n);
        for(i=1; i<n; i++)
            left[i] = max(left[i-1], height[i-1]);
        for(i=n-2; i>=0; i--)
            right[i] = max(right[i+1], height[i+1]);
        
        int level, ret=0;
        for(i=0; i<n; i++) {
            level = min(left[i], right[i]);
            ret += max(0, level-height[i]);
        }

        return ret;
    }
};

/*
# 思维过程
看了一下没有思路，只好参考下别人的题解

## 法一
参考评论区的题解，思路是把height分别左移和右移，然后求中间的凹值
*/
