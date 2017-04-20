class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def add_two_numbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        ret = ListNode(0)
        tot = 0
        backup = ret
        n1 = l1
        n2 = l2

        while (n1 != None or n2 != None):
            if n1 != None:
                tot += n1.val
                n1 = n1.next
            if n2 != None:
                tot += n2.val
                n2 = n2.next
            ret.next = ListNode(tot%10)
            tot //= 10
            ret = ret.next
        if tot == 1:
            ret.next = ListNode(1)
        print(pln(backup.next))
        return backup.next

def gln(l):
    n = ListNode(l[0])
    backup = n
    for i in range(1,len(l)):
        node = ListNode(l[i])
        n.next = node
        n = node
def pln(ln):
    ret = []
    backup = ln
    while ln != None:
        ret.append(ln.val)
        ln = ln.next
    return ret

l1 = gln([2,3,4,0,9])
l2 = gln([5,6,7])
s = Solution()
s.add_two_numbers(l1, l2)
