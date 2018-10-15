package main

import (
	"fmt"
)

func forTradicional(n int){
	for i := 0; i <= 10; i++ {
		fmt.Printf("%d x %d = %d\n", n, i, n*i)
	}
}

func forEstiloWhile(n int){
	i := 0
	for i <= 10 {
		fmt.Printf("%d x %d = %d\n", n, i, n*i)
		i++
	}
}

func main(){
	var numero int
	fmt.Print("Informe um número: ")
	fmt.Scanf("%d", &numero)
	forTradicional(numero)
	forEstiloWhile(numero)
}