package basic

import "log"

type Deque struct{
	items	[]interface{}
	size	uint64
}

func NewDeque() *Deque {
	deque := &Deque{
		items: make([]interface{}, 0),
		size: 0,
	}

	return deque
}

func (d *Deque) AddFirst(item interface{}) {
	if item == nil {
		log.Fatal("argument for AddFirst() should not nil")
	}
	if d.size == 0 {
		d.items = append(d.items, item)
		d.size++
	}else{
		tmp := make([]interface{}, 0)
		tmp = append(tmp, item)
		d.items = append(tmp, d.items...)
		d.size++
	}
}

func (d *Deque) AddLast(item interface{}) {
	if item == nil {
		log.Fatal("argument to AddLast() should not nil")
	}
	d.items = append(d.items, item)
	d.size++
}

func (d *Deque) RemoveFirst() interface{} {
	if d.size == 0 {
		log.Fatal("deque is empty")
	}
	item := d.items[0]
	d.items = d.items[1:]
	d.size--
	return item
}

func (d *Deque) RemoveLast() interface{} {
	if d.size == 0 {
		log.Fatal("deque is empty")
	}
	item := d.items[d.size-1]
	d.items = d.items[:(d.size-1)]
	d.size--
	return item

}

func (d *Deque) Size() uint64 {
	return d.size
}

func (d *Deque) IsEmpty() bool {
	return d.size == 0
}
