package main

import (
	"fmt"
)

func main (){
	var (
		n1 int
		n2 int
	)
	fmt.Print("Informe o primeiro número: ")
	fmt.Scanln(&n1)
	fmt.Print("Informe o segundo número: ")
	fmt.Scanln(&n2)
	fmt.Printf("%d - %d = %d\n", n1, n2, n1-n2)
	fmt.Printf("%d + %d = %d\n", n1, n2, n1+n2)
	fmt.Printf("%d x %d = %d\n", n1, n2, n1*n2)
	fmt.Printf("%d / %d = %d\n", n1, n2, n1/n2)
	fmt.Printf("%d %% %d = %d\n", n1, n2, n1%n2)
}