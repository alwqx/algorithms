# LeetCode

## Easy
### 14
[最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/description/)

### 21
[合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

因为是链表，所以不用额外的存储空间

注意递归的方法

### 26
[删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

1. 双指针法，最简洁的方法

### 27
[移除元素](https://leetcode-cn.com/problems/remove-element)

### 38
[报数](https://leetcode-cn.com/problems/count-and-say)

注意思路

### 53
[最大子序和](https://leetcode-cn.com/problems/maximum-subarray)

## Medium
### 3
[无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/)

自己想到了暴力解法，参考题解理解O(n)的滑动窗口解法

### 5
[最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring)

暴力解法O(n*n*n)，超时
看题解用的中心发散算法。

### 6
[Z 字形变换](https://leetcode-cn.com/problems/zigzag-conversion/description/)

自己的代码本地可以运行，但是提交线上运行报错：
```shell
Actual
  ✘ Runtime Error
  ✘ runtime: N/A
  ✘ answer: 
  ✘ stdout: ''
  ✘ error: AddressSanitizer: stack-buffer-overflow on address 0x7ffe1f59f950 at pc 0x00000040707a bp 0x7ffe1f59f350 sp 0x7ffe1f59f348
  ✘ error: =================================================================
==30==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7ffe1f59f950 at pc 0x00000040707a bp 0x7ffe1f59f350 sp 0x7ffe1f59f348
READ of size 1 at 0x7ffe1f59f950 thread T0
    #1 0x7f07e1c7f2e0 in __libc_start_main (/lib/x86_64-linux-gnu/libc.so.6+0x202e0)

Address 0x7ffe1f59f950 is located in stack of thread T0 at offset 1408 in frame

  This frame has 24 object(s):
    [32, 33) '<unknown>'
    [96, 97) '<unknown>'
    [160, 161) '<unknown>'
    [224, 225) '<unknown>'
    [288, 289) '<unknown>'
    [352, 353) '<unknown>'
    [416, 417) '<unknown>'
    [480, 481) '<unknown>'
    [544, 545) '<unknown>'
    [608, 609) '<unknown>'
    [672, 673) '<unknown>'
    [736, 737) '<unknown>'
    [800, 801) '<unknown>'
    [864, 865) '__c'
    [928, 932) 'SEPARATOR'
    [992, 1000) '__new_capacity'
    [1056, 1088) 'line'
    [1120, 1152) 'param_1'
    [1184, 1216) 'ret'
    [1248, 1280) '<unknown>'
    [1312, 1344) 'out'
    [1376, 1408) '<unknown>' <== Memory access at offset 1408 overflows this variable
    [1440, 1472) 'ret'
    [1504, 2016) 'fout'
HINT: this may be a false positive if your program uses some custom stack unwind mechanism or swapcontext
      (longjmp and C++ exceptions *are* supported)
Shadow bytes around the buggy address:
  0x100043eabed0: f2 f2 f2 f2 f2 f2 01 f2 f2 f2 f2 f2 f2 f2 01 f2
  0x100043eabee0: f2 f2 f2 f2 f2 f2 01 f2 f2 f2 f2 f2 f2 f2 04 f2
  0x100043eabef0: f2 f2 f2 f2 f2 f2 00 f2 f2 f2 f2 f2 f2 f2 00 00
  0x100043eabf00: 00 00 f2 f2 f2 f2 00 00 00 00 f2 f2 f2 f2 00 00
  0x100043eabf10: 00 00 f2 f2 f2 f2 00 00 00 00 f2 f2 f2 f2 00 00
=>0x100043eabf20: 00 00 f2 f2 f2 f2 00 00 00 00[f2]f2 f2 f2 00 00
  0x100043eabf30: 00 00 f2 f2 f2 f2 00 00 00 00 00 00 00 00 00 00
  0x100043eabf40: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100043eabf50: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100043eabf60: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100043eabf70: 00 00 00 00 00 00 f3 f3 f3 f3 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==30==ABORTING

Expected
  ✔ runtime: 32 ms
  ✔ answer: "PAHNAPLSIIGYIR"
  ✔ stdout: ''
```
这种问题的原因是非法访问内存，可能是下表溢出

### 11
[盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/description/)

双指针法，从两侧逼近