#include <iostream>
#include <vector>
#include <string>

using namespace std;

class QuickSort{
public:
    int partition(vector<string>& nums, int left, int right) {
        string piv=nums[left];
        int pos=left;
        swap(nums[left], nums[right]);
        for(int i=left; i<=right; i++) {
            if(nums[i] < piv) swap(nums[i], nums[pos++]);
        }
        swap(nums[pos], nums[right]);
        return pos;
    }

    int rand_partition(vector<string>& nums, int left, int right) {
        int pos = rand() % (right-left+1) + left;
        swap(nums[pod], nums[right]);
        return partition(nums, left, right);
    }

    void sort(vector<string>& nums, int left, int right) {
        if(left >= right) return;
        int piv = partition(nums, left, right);
        sort(nums, left, piv-1);
        sort(nums, piv+1, right);
    }

    // 快速选择数组中第K大数字
    string select(vector<string>& nums, int k) {
        if(k<1 || k>nums.size()) return "";
        k--;
        int piv, left=0, right=nums.size()-1;
        while(left < right) {
            piv = partition(nums, left, right);
            if(piv == k) return nums[k];
            else if(k > piv) left = piv+1;
            else right = piv-1;
        }

        return nums[left];
    }
};

void pp(vector<string>&);
void shullfle(vector<string>&);

int main() {
    QuickSort* qs = new QuickSort();
    vector<string> nums;
    string str;
    while(cin>>str) {
        nums.push_back(str);
    }

    pp(nums);
    qs->sort(nums, 0, nums.size()-1);
    pp(nums);

    shullfle(nums);
    cout<<qs->select(nums, 3)<<endl;
    cout<<qs->select(nums, 5)<<endl;
    cout<<qs->select(nums, 1)<<endl;

    return 0;
}

void pp(vector<string>& nums) {
    int size = nums.size();
    for(int i=0; i<size; i++) {
        if(i < size-1) cout<<nums[i]<<" ";
        else cout<<nums[size-1]<<endl;
    }
}

void shullfle(vector<string>& nums) {
    int i, j;
    for(i=nums.size()-1; i>=0; i--) {
        j = rand() % (i+1);
        swap(nums[i], nums[j]);
    }
}