package basic

import(
	"testing"
)

func TestStack(t *testing.T) {
	s := NewStack()
	s.Push("a")
	s.Push(2)
	if s.Size() != 2 {
		t.Error("stack size not equal 2")
	}

	if item := s.Pop(); item != 2 {
		t.Error("pop not equal 2")
	}
}
