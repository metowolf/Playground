package main

import (
	"fmt"
)

func main() {
	var a, b, x int
	fmt.Scan(&a, &b, &x)
	if min(a, b)+x > max(a, b) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
