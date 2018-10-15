package main

import (
	"fmt"
	"strconv"
)

func main(){
	var texto string
	print("Informe um número: ")
	fmt.Scanf("%s", &texto)
	var numAtoi int
	numAtoi, _ = strconv.Atoi(texto)
	numAtoi++
	var numParse, _ = strconv.ParseInt(texto, 10, 32)
	println("Número(Atoi): ", numAtoi)
	println("Número(parse): ", numParse)
}