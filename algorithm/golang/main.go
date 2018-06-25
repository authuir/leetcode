package main

import "fmt"
import "time"

func main() {
	go fmt.Println("Main Func")
	time.Sleep(1000)
	fmt.Println("Main Func")
}
