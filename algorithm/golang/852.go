package main

func peakIndexInMountainArray(A []int) int {
	var rtn int
	var left int
	var right int
	left = 0
	right = len(A) - 1
	rtn = len(A) / 2
	for {
		if A[rtn] > A[rtn-1] && A[rtn] > A[rtn+1] {
			return rtn
		} else if A[rtn] > A[rtn-1] && A[rtn] < A[rtn+1] {
			left = rtn
			rtn = (left + right) / 2
		} else if A[rtn] < A[rtn-1] && A[rtn] > A[rtn+1] {
			right = rtn
			rtn = (left + right) / 2
		}
	}
}
