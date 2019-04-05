// refer https://leetcode-cn.com/problemset/algorithms/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;

void v1(vector<int>& nums, int target) {
    vector<int> ret;
    int i, j;
    int stop = false;
    for(i=0; i<nums.size()-1; i++) {
        for(j=i+1; j<nums.size(); j++) {
            printf("%d %d %d\n", nums[i], nums[j], nums[i]+nums[j]);
            if(nums[i]+nums[j] == target) {
                ret.push_back(i);
                ret.push_back(j);
                stop = true;
                break;
            }
        }
        if(stop) {
            printf("%d %d\n", ret[0], ret[1]);
            break;
        }
    }
}

void v2(vector<int>& nums, int t) {
    map<int, int> m;
    vector<int> ret;
    int  i, j;

    for(i=0; i<nums.size(); i++)
        m[nums[i]] = i;
    
    map<int, int>::iterator itr;
    for(i=0; i<nums.size(); i++) {
        itr = m.find(t-nums[i]);
        if(itr != m.end() && itr->second!=i) {
            ret.push_back(i);
            // ret.push_back(m[t-nums[i]]);
            ret.push_back(itr->second);
            break;
        }
    }
    
    printf("%d %d\n", ret[0], ret[1]);
}

void v3(vector<int>& nums, int t) {
    map<int, int> m;
    vector<int> ret;
    int  i, j;
    
    map<int, int>::iterator itr;
    for(i=0; i<nums.size(); i++) {
        itr = m.find(t-nums[i]);
        if(itr != m.end()) {
            ret.push_back(itr->second);
            ret.push_back(i);
            break;
        }
        m[nums[i]] = i;
    }
    
    printf("%d %d\n", ret[0], ret[1]);
}

int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    v3(nums, target);

    return 0;
}