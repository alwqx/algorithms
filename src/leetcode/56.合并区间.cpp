/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (35.23%)
 * Total Accepted:    12.9K
 * Total Submissions: 36.5K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
};*/
 
bool cmp(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return intervals;
        vector<Interval> ret;
        int start, end, i;

        sort(intervals.begin(), intervals.end(), cmp);
        for(i=0; i<intervals.size(); i++) {
            if(i == 0) {
                start = intervals[i].start;
                end = intervals[i].end;
                continue;
            }
            
            if(intervals[i].start > end) {
                ret.push_back(*(new Interval(start, end)));
                start = intervals[i].start;
                end = intervals[i].end;
            } else if (intervals[i].end > end) end = intervals[i].end;
        }

        ret.push_back(*(new Interval(start, end)));
        return ret;
    }
};

/*
int main() {
    vector<Interval> cases;
    cases.push_back(*(new Interval(1, 3)));
    cases.push_back(*(new Interval(2, 6)));
    cases.push_back(*(new Interval(8, 10)));
    cases.push_back(*(new Interval(15, 18)));
    
    auto ret = Solution().merge(cases);
    for(int i=0; i<ret.size(); i++) {
        printf("%d %d\n", ret[i].start, ret[i].end);
    }
    return 0;
}*/
