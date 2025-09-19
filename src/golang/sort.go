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
