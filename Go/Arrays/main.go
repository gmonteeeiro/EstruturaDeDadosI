package main

import (
	"fmt"
)

func main() {
	var amigos [5]string

	for i := 0; i < len(amigos); i++ {
		fmt.Print("Digite o nome: ")
		fmt.Scanln("%s", &amigos[i])
	}

	fmt.Print("Seus amigos são:\n")
	for _, amigo := range amigos {
		fmt.Printf("\t-%s", amigo)
	}
}
