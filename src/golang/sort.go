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
