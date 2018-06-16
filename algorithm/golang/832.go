package main

func flipAndInvertImage(A [][]int) [][]int {
	xLen := len(A)
	var rtn [][]int
	if xLen <= 0 {
		return rtn
	}
	yLen := len(A[0])
	yyLen := yLen
	if yyLen%2 == 1 {
		yyLen++
	}

	for i := 0; i < xLen; i++ {
		for j := 0; j < yyLen/2; j++ {
			tmp1 := A[i][j]
			tmp2 := A[i][yLen-j-1]
			if tmp1 == 1 {
				A[i][yLen-j-1] = 0
			} else {
				A[i][yLen-j-1] = 1
			}
			if tmp2 == 1 {
				A[i][j] = 0
			} else {
				A[i][j] = 1
			}
		}
	}
	return A
}
