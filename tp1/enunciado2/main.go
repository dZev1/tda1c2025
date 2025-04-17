package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
    reader := bufio.NewReader(os.Stdin)

    s1, _ := reader.ReadString('\n')
    s1 = strings.TrimSpace(s1)

	posFinal := 0
	for _, c := range s1 {
		if c == '+' {
			posFinal++
		} else if c == '-' {
			posFinal--
		}
	}

    s2, _ := reader.ReadString('\n')
    s2 = strings.TrimSpace(s2)

	solValidas, solTotales  := CalcularSoluciones(s2, posFinal)

	probabilidad := float64(solValidas) / float64(solTotales)

	fmt.Printf("%.10f\n", probabilidad)

}

func CalcularSoluciones(s2 string, posFinal int) (int, int) {
	var backtrack func(i, suma int) int

	contadorComodin := 0
	for _, val := range s2 {
		if val == '?' {
			contadorComodin++
		} 
	}

	backtrack = func(i, suma int) int {
		if i == len(s2) {
			if suma == posFinal {
				return 1
			}
			return 0
		}

		if s2[i] == '?' {
			return backtrack(i+1, suma+1) + backtrack(i+1, suma-1)
		}
		if s2[i] == '+' {
			return backtrack(i+1, suma+1)
		}
		if s2[i] == '-' {
			return backtrack(i+1, suma-1)
		}
		return 0
    }

	solValidas := backtrack(0, 0)

	solTotales := 1 << contadorComodin

	return solValidas, solTotales 
}