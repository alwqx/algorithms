package basic

import "testing"

func TestDeque(t *testing.T) {
	d := NewDeque()
	d.AddFirst("a") // ["a"]
	d.AddFirst(2) // [2, "a"]
	if d.RemoveFirst() != 2 {
		t.Error("Deque test error")
	}

	d.AddLast("b") // ["a", "b"]
	d.AddLast("c") // ["a", "b", "c"]
	
	if d.RemoveLast() != "c" {
		t.Error("Deque test error")
	}
}
