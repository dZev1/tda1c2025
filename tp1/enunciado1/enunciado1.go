package main
 
import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
 
func main() {
	var t int
	fmt.Scan(&t)
 
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)
 
	for testCase := 0; testCase < t; testCase++ {
		for scanner.Scan() {
			line := scanner.Text()
			if len(strings.TrimSpace(line)) == 0 {
				continue
			}
			dims := strings.Fields(line)
			N, _ := strconv.Atoi(dims[0])
			M, _ := strconv.Atoi(dims[1])
 
			G := make([][]int, N)
			leerCols := 0
 
			for leerCols < N && scanner.Scan() {
				col := scanner.Text()
				if len(strings.TrimSpace(col)) == 0 {
					continue
				}
				values := strings.Fields(col)
				G[leerCols] = make([]int, M)
				for j := 0; j < M; j++ {
					G[leerCols][j], _ = strconv.Atoi(values[j])
				}
				leerCols++
			}
 
			if HaySolucion(G) {
				fmt.Println("YES")
			} else {
				fmt.Println("NO")
			}
			break
		}
	}
}

func HaySolucion(G [][]int) bool {
	n := len(G)
	m := len(G[0])
	totalSteps := n + m - 1
 
	if totalSteps % 2 != 0 {
		return false
	}
 
	memo := make(map[[3]int]bool)
 
	var dp func(i, j, suma int) bool
	dp = func(i, j, suma int) bool {
		if i >= n || j >= m {
			return false
		}
 
		suma += G[i][j]
 
		if i == n - 1 && j == m - 1 {
			return suma == 0
		}
        
        movimientosRestantes := (n - i - 1) + (m - j - 1)

        if suma - movimientosRestantes > 0 || suma + movimientosRestantes < 0 {
            return false
        }

		key := [3]int{i, j, suma}
		if val, ok := memo[key]; ok {
			return val
		}
 
        resultado := false
        if j+1 < m {
            resultado = resultado || dp(i, j+1, suma)
        }
        if i+1 < n && !resultado {
            resultado = resultado || dp(i+1, j, suma)
        }

		memo[key] = resultado
		return resultado
	}
 
	return dp(0, 0, 0)
}