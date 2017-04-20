package leetcode

import "testing"

func TestAddTwoNumbers(t *testing.T) {
	n1 := &ListNode{1, nil}
	n2 := &ListNode{1, nil}
	n3 := &ListNode{1, nil}
	n4 := &ListNode{1, nil}
	n5 := &ListNode{1, nil}
	n6 := &ListNode{1, nil}

	n2.Next = n3
	n1.Next = n2
	n5.Next = n6
	n4.Next = n5
	
	ret := AddTwoNumbers(n1, n4)
	
	for ret != nil {
		if ret.Val != 2 {
			t.Errorf("ret.val should 2, got %d", ret.Val)
		}
		ret = ret.Next
	}
}
