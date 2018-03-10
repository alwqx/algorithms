package basic

import "testing"

func TestQueue(t *testing.T) {
	q := NewQueue()
	q.Enqueue(1)
	q.Enqueue("a")
	q.Enqueue("b")

	if q.Dequeue() != 1 {
		t.Error("element in Queue error")
	}

	if q.Size() != 2 {
		t.Error("Queue error")
	}
}
