# CPP LeetCode Debug

## AddressSanitizer: SEGV on unknown address

[What does AddressSanitizer: SEGV on unknown address 0x000000000000 mean?](https://stackoverflow.com/questions/61078676/what-does-addresssanitizer-segv-on-unknown-address-0x000000000000-mean)

> It means that you are dereferencing a null pointer somewhere in your code

引用指向空指针，编译 AddressSanitizer 检查不通过。

参考提交代码 [reverse-linked-list-ii/submissions/604067409](https://leetcode.cn/problems/reverse-linked-list-ii/submissions/604067409/)
