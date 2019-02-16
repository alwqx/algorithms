# 链表
使用链式存储结构，`理解链表是学习各种算法和数据结构最关键的第一步`。

这里通过实现背包`Bag`来理解链表这个数据结构。

## 背包
### 定义
1. 不支持删除的集合类数据结构
2. 迭代顺序不确定且与用例无关

### API
```java
Bag()
isEmpty()
size()
add(Item item)
```

代码见[Bag.java](https://github.com/adolphlwq/algorithms/blob/master/src/java/utils/Bag.java ':include')
运行测试代码：
```shell
cd algorithms
make compile-bag
make test-bag
```

## 分析
Bag是一个简单的前插链表，拥有一个头节点。

插入的时间复杂度是O(1).