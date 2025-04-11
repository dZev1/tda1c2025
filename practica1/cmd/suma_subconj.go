package main

import (
	"fmt"
)

var res [][]int

func main() {
	conjunto := []int{6,12,6}
	solParcial := []int {}
	n := 12
	fmt.Println("Conjunto: ", conjunto)
	fmt.Println("Suma de subconjuntos:", n)
	fmt.Println("Hay solucion??", HaySolucion(conjunto, len(conjunto)-1, 12))
	SumaSubconjuntos(conjunto, len(conjunto) - 1, n, solParcial)
	fmt.Println(res)
}

func SumaSubconjuntos(C []int, index, target int, solParcial []int) {
	if target < 0 {
		return
	}
	if index < 0 {
		if target == 0 {
			copia := append([]int{}, solParcial...)
			res = append(res, copia)
		}
		return
	}
	solParcial = append(solParcial, C[index])
    SumaSubconjuntos(C, index-1, target-C[index], solParcial)
    solParcial = solParcial[:len(solParcial)-1]
    SumaSubconjuntos(C, index-1, target, solParcial)
	
}

func HaySolucion(C []int, index, target int) bool {
	if target < 0 {
		return false
	}
	if index < 0 {
		return target == 0
	}
	return HaySolucion(C, index-1, target-C[index]) || HaySolucion(C, index-1, target)
}