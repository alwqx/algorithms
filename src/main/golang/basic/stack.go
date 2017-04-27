package basic

import(
	"log"
)

type Stack struct{
	items 	[]interface{}
	size	uint64
}

func NewStack() *Stack {
	s := &Stack{
		items: make([]interface{}, 0),
		size: 0,
	}
	return s
}

func (s *Stack) Push(item interface{}) {
	if item == nil {
		log.Fatal("argument to Pop() should not nil!")
	}
	s.items = append(s.items, item)
	s.size ++
}

func (s *Stack) Pop() (item interface{}) {
	if s.size == 0 {
		log.Fatal("Stack has no element!")
	}
	item = s.items[s.size - 1]
	s.items = s.items[:s.size-1]
	s.size--
	return item
}

func (s *Stack) Peek() (item interface{}) {
	if s.size == 0 {
		log.Fatal("Stack has no element!")
	}
	return s.items[s.size - 1]
}

func (s *Stack) IsEmpty() bool {
	return s.size == 0
}

func (s *Stack) Size() uint64 {
	return s.size
}
