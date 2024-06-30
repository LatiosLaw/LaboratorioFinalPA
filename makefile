# Nombre del ejecutable
EXEC = programa.exe

# Directorios de código fuente
SRC_DIRS = ./negocio/dominio/cpp ./negocio/dto ./negocio/controller ./presentacion

# Archivos fuente
SRCS = main.cpp $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Compilador y flags
CXX = g++
CXXFLAGS = -std=c++11

# Regla por defecto
all: $(EXEC)

# Regla para compilar el ejecutable
$(EXEC): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(EXEC)

# Regla para limpiar
clean:
	rm -f $(EXEC)

# Regla para ejecutar
run: $(EXEC)
	./$(EXEC)