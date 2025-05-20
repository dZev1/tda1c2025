# Makefile para compilar y ejecutar ParejasDeBaile.cpp

# Variables
CXX = g++
SRC = ParejasDeBaile.cpp
OUT = parejas.exe
EXE = ./$(OUT)

# Regla por defecto
all: $(OUT)

# Regla para compilar
$(OUT): $(SRC)
	$(CXX) $(SRC) -o $(OUT)

# Regla para ejecutar
run: $(OUT)
	$(EXE)

# Limpiar archivos generados
clean:
	rm -f $(OUT)
