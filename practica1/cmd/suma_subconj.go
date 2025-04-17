package main

var res [][]int

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

func HaySolucion(C []int, index, target int) int {
	if target < 0 {
		return 0
	}
	if index < 0 {
		if target == 0 {
			return 1
		}
		return 0
	}
	return HaySolucion(C, index-1, target-C[index]) + HaySolucion(C, index-1, target)
}