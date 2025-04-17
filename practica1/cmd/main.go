package main

import (
	"fmt"
)

func main() {
	conjunto := []int{6,12,6}
	solParcial := []int {}
	n := 12
	fmt.Println("Conjunto: ", conjunto)
	fmt.Println("Suma de subconjuntos:", n)
	fmt.Println("Cuantas soluciones hay??", HaySolucion(conjunto, len(conjunto)-1, 12))
	SumaSubconjuntos(conjunto, len(conjunto) - 1, n, solParcial)
	fmt.Println(res)
}