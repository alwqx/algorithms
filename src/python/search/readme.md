# Python data structure
## binary search
在递归实现二叉搜索中，要注意初始情况，如果判断不正确会出现无限次递归。

```
def recursion_binary_searchi(alist, item, first=None, last=None):
    if first > last:
        return False

    print('first is {} last is {}'.format(first, last))

    mid = (first + last)//2

    if alist[mid] == item:
        return True
    elif alist[mid] > item:
        return recursion_binary_searchi(alist, item, first, mid-1)
    else:
        return recursion_binary_searchi(alist, item, mid+1, last)
```

中`first>last` ==> `first>=last`

## HashTable
HashTable中的`put()`和`get()`还需要多看看，多写几次来加深理解。
