package basic

import "log"

type Queue struct {
	items	[]interface{}
	size	uint64
}

func NewQueue() *Queue {
	q := &Queue{
		items: make([]interface{}, 0),
		size: 0,
	}
	return q
}

func (q *Queue) Enqueue(item interface{}) {
	if item == nil {
		log.Fatal("argument for Enqueue() should not nil")
	}
	q.items = append(q.items, item)
	q.size++
}

func (q *Queue) Dequeue() interface{} {
	if q.IsEmpty() {
		log.Fatal("Queue is empty")
	}
	item := q.items[0]
	q.items = q.items[1:]
	q.size--
	return item
}

func (q *Queue) IsEmpty() bool {
	return q.size == 0
}

func (q *Queue) Size() uint64 {
	return q.size
}
