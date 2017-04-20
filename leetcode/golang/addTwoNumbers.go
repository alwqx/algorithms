package leetcode

type ListNode struct {
	Val int
	Next *ListNode
}

func AddTwoNumbers(l1, l2 *ListNode) *ListNode {
	tot := 0
	var n1 *ListNode = l1
	var n2 *ListNode = l2
	ret := &ListNode{Val:0, Next: nil}
	var backup *ListNode = ret

	for n1 != nil || n2 != nil {
		if n1 != nil {
			tot += n1.Val
			n1 = n1.Next
		}

		if n2 != nil {
			tot += n2.Val
			n2 = n2.Next
		}

		ret.Next = &ListNode{Val: tot%10, Next: nil}
		ret = ret.Next
		tot = tot/10
	}

	if tot == 1 {
		ret.Next = &ListNode{Val: 1, Next: nil}
	}

	return backup.Next
}

