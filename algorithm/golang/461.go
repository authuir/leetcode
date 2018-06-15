package main

func hammingDistance(x int, y int) int {
	var rtn int
	var i uint32
	for i = 0; i < 32; i++ {
		if ((x >> i) & 0x01) != ((y >> i) & 0x01) {
			rtn++
		}
	}
	return rtn
}
