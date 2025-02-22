# C++基础

# 常用数据结构

- vector
- queue
- stack
- pair
- list
- map unordered_map

可参考 [w3schools | Data Structures](https://www.w3schools.com/cpp/cpp_vectors.asp) 快速过一遍常用数据结构的操作。

# sort 中的 cmp 函数

1. 基本数据类型可以直接比较，也可以自定义 cmp 实现递增、递减排序。

```cpp
class Solution {
public:
    static bool cmp(const int &a, const int &b) {
        return a<b;
    }

    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[nums.size()/2];
    }
};
```

2. 结构体数组的排序

```cpp
struct node {
    int x, y;
}
bool cmp(node a, node b) {
    return a.x > b.x;
}
void main() {
    sort(arr.begin(), arr.end(), cmp);
}
```

3. 容器的排序
   只有 vector、string 和 deque 是可以排序的，像 map、set 这样底层使用红黑树实现，本身是有序的，是不允许排序的。vector 的排序，里面的元素是 int，所以用 int

```cpp
bool cmp(int a, int b) {
    return a>b;
}
void main() {
    vector<int> arr;
    // init arr
    sort(arr.begin(), arr.end(), cmp);
}
```

4. string 的排序

```cpp
bool cmp(string a, string b) {
    return a.size() > b.size();
}
void main() {
    vector<string> arr;
    // init arr
    sort(arr.begin(), arr.end(), cmp);
}
```
