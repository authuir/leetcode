package main

func rotatedDigits(N int) int {
	rtn := 0
	for i := 1; i <= N; i++ {
		if isRotated(i) {
			rtn++
		}
	}
	return rtn
}

func isRotated(N int) bool {
	rtn := false
	for {
		n := N % 10
		N = N / 10
		if n == 0 || n == 1 || n == 8 {

		} else if n == 2 || n == 5 || n == 6 || n == 9 {
			rtn = true
		} else {
			rtn = false
			break
		}
		if N <= 0 {
			break
		}
	}
	return rtn
}

// func main() {
// 	rotatedDigits(10)
// }
