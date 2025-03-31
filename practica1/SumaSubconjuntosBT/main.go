package main

import "fmt"

func main() {
	C := []int{6, 12, 6}
	k := 12
	parcial := []int{}

	soluciones := solve(C, k, parcial, [][]int{})
	
	fmt.Println(soluciones)

}

func solve(C []int, k int, parcial []int, soluciones [][]int) [][]int {
    sum := 0
    for _, num := range parcial {
        sum += num
    }

    if sum == k {
        sol := make([]int, len(parcial))
        copy(sol, parcial)
        return append(soluciones, sol)
    }

    if sum > k || len(C) == 0 {
        return soluciones
    }

    soluciones = solve(C[1:], k, append(parcial, C[0]), soluciones)

    soluciones = solve(C[1:], k, parcial, soluciones)

    return soluciones
}