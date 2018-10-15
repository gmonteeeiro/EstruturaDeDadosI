package main

import (
	"fmt"
)

func main(){
	var amigos [5]string
	// fmt.Println(amigos)

	for i := 0; i < len(amigos); i++ {
		fmt.Printf("Informe o %dº amigo: ", i+1)
		fmt.Scanf("%s", &amigos[i])
	} 

	fmt.Println("Seus amigos são:\n")
	for i := 0; i < len(amigos); i++{
		fmt.Printf("* %s", amigos[i])
	}
}