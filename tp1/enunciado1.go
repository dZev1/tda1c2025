package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)
func main() {
	reader := bufio.NewReader(os.Stdin)
    writer := bufio.NewWriter(os.Stdout)
    defer writer.Flush()

    var t int
    fmt.Fscanf(reader, "%d\n", &t)

    results := make([]string, t)

    for caseIndex := 0; caseIndex < t; caseIndex++ {
        
        line, _ := reader.ReadString('\n')
        dimensions := strings.Fields(line)
        n, _ := strconv.Atoi(dimensions[0])
        m, _ := strconv.Atoi(dimensions[1])

        
        grid := make([][]int, n)
        for i := 0; i < n; i++ {
            line, _ := reader.ReadString('\n')
            row := strings.Fields(line)
            grid[i] = make([]int, m)
            for j := 0; j < m; j++ {
                grid[i][j], _ = strconv.Atoi(row[j])
            }
        }

		if isPossible(grid, n, m) {
            results[caseIndex] = "YES"
        } else {
            results[caseIndex] = "NO"
        }
	}
	
	for _, result := range results {
        fmt.Fprintln(writer, result)
    }
}

func isPossible(grid [][]int, n, m int) bool {
    
    return false
}