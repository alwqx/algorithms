package algo

import "testing"

func TestQuickSort(t *testing.T) {
	arr1 := []int{9, 8, 7, 6, 5, 4, 3, 2, 1}
	QuickSort(arr1)
	exp1 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	if len(arr1) != len(exp1) {
		t.Fail()
	}
	for i, v := range arr1 {
		if exp1[i] != v {
			t.Fail()
		}
	}
}

func TestMergeSort(t *testing.T) {
	arr1 := []int{9, 8, 7, 6, 5, 4, 3, 2, 1}
	MergeSort(arr1)
	exp1 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	if len(arr1) != len(exp1) {
		t.Fail()
	}
	for i, v := range arr1 {
		if exp1[i] != v {
			t.Fail()
		}
	}
}

func TestHeapSort(t *testing.T) {
	arr1 := []int{9, 8, 7, 6, 5, 4, 3, 2, 1}
	HeapSort(arr1)
	exp1 := []int{1, 2, 3, 4, 5, 6, 7, 8, 9}
	if len(arr1) != len(exp1) {
		t.Fail()
	}
	for i, v := range arr1 {
		if exp1[i] != v {
			t.Fail()
		}
	}
}
