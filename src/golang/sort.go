package algo

func QuickSort(arr []int) {
	if len(arr) <= 1 {
		return
	}

	size := len(arr)
	quick(arr, 0, size-1)
}

func quick(arr []int, low, high int) {
	if low >= high {
		return
	}

	mid := partition(arr, low, high)
	quick(arr, low, mid-1)
	quick(arr, mid+1, high)
}

func partition(arr []int, low, high int) int {
	pivot := arr[low]
	arr[low] = arr[high]
	arr[high] = pivot

	pos := low
	for i := low; i <= high; i++ {
		if arr[i] < pivot {
			tmp := arr[i]
			arr[i] = arr[pos]
			arr[pos] = tmp
			pos++
		}
	}

	arr[high] = arr[pos]
	arr[pos] = pivot

	return pos
}

func MergeSort(arr []int) {
	num := len(arr)
	if num <= 1 {
		return
	}

	holder := make([]int, num)
	mergeSortHelper(arr, holder, 0, num-1)
}

func mergeSortHelper(arr, holder []int, low, high int) {
	if low >= high {
		return
	}

	mid := (low + high) / 2
	mergeSortHelper(arr, holder, low, mid)
	mergeSortHelper(arr, holder, mid+1, high)
	merge(arr, holder, low, mid, high)
}

func merge(arr, holder []int, low, mid, high int) {
	for i := low; i <= high; i++ {
		holder[i] = arr[i]
	}

	i := low
	j := mid + 1
	for k := low; k <= high; k++ {
		if i > mid {
			arr[k] = holder[j]
			j++
		} else if j > high {
			arr[k] = holder[i]
			i++
		} else if holder[i] < holder[j] {
			arr[k] = holder[i]
			i++
		} else {
			arr[k] = holder[j]
			j++
		}
	}
}

func HeapSort(arr []int) {
	// 先堆化，数组原地构建大顶堆
	n := len(arr)
	// 左子树的根节点 (n-1)/2   left=i*2+1
	// 右子树的根节点 n/2 - 1	right=i*2+2
	// 默认 n 是右子树的节点序号？
	for i := n/2 - 1; i >= 0; i-- {
		shiftDown(arr, n, i)
	}

	// 从堆中取最大元素，循环 n-1 轮
	// n-1 是下标
	for i := n - 1; i > 0; i-- {
		// 交换根节点与叶子节点元素
		t := arr[0]
		arr[0] = arr[i]
		arr[i] = t

		shiftDown(arr, i, 0)
	}
}

// shiftDown 数组从根节点 i 开始堆化
// n 是数组的长度，i是根节点索引
func shiftDown(arr []int, n, i int) {
	for {
		l := i*2 + 1 // 左节点
		r := i*2 + 2 // 右节点
		ma := i

		if l < n && arr[l] > arr[ma] {
			ma = l
		}
		if r < n && arr[r] > arr[ma] {
			ma = r
		}
		if ma == i {
			break
		}

		tmp := arr[i]
		arr[i] = arr[ma]
		arr[ma] = tmp
		i = ma
	}
}
