package main

import (
	"fmt"
)

func EstIf() {
	const adult int = 18

	var idade int
	fmt.Print("Informe a sua idade: ")
	fmt.Scanf("%d", &idade)

	if idade >= adult {
		fmt.Println("Você é adulto!")
	}else{
		fmt.Println("Você ainda não é adulto")
	}

	//GO não suporta operador ternário :/
	//fmt.Println("Você é %s", idade >= adult ? "um adulto" : "um menor de idade");
}

func EstSwitch(){
	var mes int
	fmt.Print("Informe o número do mês: ")
	fmt.Scanf("%d", &mes)
	switch mes {
	case 1:
		fmt.Println("Janeiro")
	case 2:
		fmt.Println("Favereiro")
	case 3:
		fmt.Println("Março")
	case 4:
		fmt.Println("Abril")
	case 5:
		fmt.Println("Maio")
	case 6:
		fmt.Println("Junho")
	case 7:
		fmt.Println("Julho")
	case 8:
		fmt.Println("Agosto")
	case 9:
		fmt.Println("Setembro")
	case 10:
		fmt.Println("Outubro")
	case 11:
		fmt.Println("Novembro")
	case 12:
		fmt.Println("Dezembro")
	default:
		fmt.Println("Mês inválido!")
	}

	switch (mes){
	case 1,2,3,4,5,6:
		fmt.Println("Primeiro semestre")
	case 7,8,9,10,11,12:
		fmt.Println("Primeiro semestre")
	default:
		fmt.Println("Mês inválido!")
	}
}

func main(){
	//EstIf();
	EstSwitch()
	fmt.Printf("\nFim")
}