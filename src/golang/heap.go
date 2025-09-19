package algo

type maxHeap struct {
	data []int
}

func NewMaxHeap(arr []int) *maxHeap {
	h := &maxHeap{
		data: arr,
	}
	return h
}

func (h *maxHeap) left(i int) int {
	return i*2 + 1
}

func (h *maxHeap) right(i int) int {
	return i*2 + 2
}

func (h *maxHeap) parent(i int) int {
	return (i - 1) / 2
}

func (h *maxHeap) peek() int {
	return h.data[0]
}

func (h *maxHeap) push(v int) {
	h.data = append(h.data, v)
	h.shiftUp(len(h.data) - 1)
}

func (h *maxHeap) shiftUp(i int) {
	for true {
		p := h.parent(i)
		// 当越过根节点，或者根节点不需要修复时，结束
		if p < 0 || h.data[p] >= h.data[i] {
			break
		}
		// 交换节点
		h.swap(i, p)
		// 循环向上
		i = p
	}
}

func (h *maxHeap) swap(i, j int) {
	tmp := h.data[i]
	h.data[i] = h.data[j]
	h.data[j] = tmp
}

// pop 堆顶元素出堆
func (h *maxHeap) pop() int {
	if h.isEmpty() {
		return 0
	}

	n := len(h.data)
	h.swap(0, n-1)
	v := h.data[n-1]
	h.data = h.data[:n-1]
	h.shiftDown(0)

	return v
}

// pop 堆顶元素出堆
func (h *maxHeap) isEmpty() bool {
	return len(h.data) == 0
}

// pop 堆顶元素出堆
func (h *maxHeap) size() int {
	return len(h.data)
}

// shiftDown 自顶向下堆化
func (h *maxHeap) shiftDown(i int) {
	for true {
		// 根节点 i 左子树l 右子树 r
		l := h.left(i)
		r := h.right(i)
		m := i

		// 找到值最大的节点索引
		n := h.size()
		if l < n && h.data[l] > h.data[m] {
			m = l
		}
		if r < n && h.data[r] > h.data[m] {
			m = r
		}
		// 暂停条件
		if m == i {
			break
		}
		h.swap(i, m)
		i = m
	}
}
