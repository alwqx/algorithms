/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (34.35%)
 * Total Accepted:    46.8K
 * Total Submissions: 136.2K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * A = [1, 3]
 * B = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * A = [1, 2]
 * B = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void pp(vector<int>& a) {
    int i;
    for(i=0; i<a.size(); i++) printf("%d ", a[i]);
    putchar('\n');
}

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m=A.size(), n=B.size();
        // printf("%d %d\n", m, n);
        // pp(A);pp(B);
        if(m>n) {
            A.swap(B);
            int t = m; m = n; n = t;
        }
        // printf("%d %d\n", m, n);
        // pp(A);pp(B);

        int imin=0, imax=m, mid=(m+n+1)/2;
        while(imin <= imax) {
            int i = (imin + imax)/2;
            int j = mid-i;

            if(i<imax && B[j-1]>A[i]) imin=i+1;
            else if(i>imin && A[i-1]>B[j]) imax = i-1;
            else {
                int maxLeft = 0;
                if(i == 0) maxLeft = B[j-1];
                else if(j == 0) maxLeft = A[i-1];
                else maxLeft = max(A[i-1], B[j-1]);

                if((m+n)%2 == 1) return maxLeft;

                int minRight = 0;
                if(i == m) minRight = B[j];
                else if(j == n) minRight = A[i];
                else minRight = min(B[j], A[i]);

                return (maxLeft+minRight)/2.0;
            }
        }

        return 0.0;
    }
};

/*
int main() {
    Solution s = Solution();
    vector<int> A = {1,2,3}, B={4};
    printf("%f\n", s.findMedianSortedArrays(A, B));

    return 0;
}
*/
/*
# 思维过程
一开始没有满足限制条件的思路，自己尝试在两个数组上使用二分查找来做，也没有想好具体实现。

然后看了解析，解析是**从中位数的概念入手**，先假设如果是中位数，应该满足什么条件，然后根据满足的条件，回去倒推解决方案。
这种**逆向思维**方法值得借鉴。

另外，我相信大部分人在分析时都会有意无意使用逆向思维的方法，但是能够找到逆向中的关键，决定这能否解决问题。
*/
