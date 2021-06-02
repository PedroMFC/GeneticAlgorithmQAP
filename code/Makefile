SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib
CXX = g++
CPPFLAGS = -Wall -g -c -std=c++11

all: normal lamarck baldwin

normal: $(BIN)/normal 

baldwin: $(BIN)/baldwin

lamarck: $(BIN)/lamarck

runNormal: normal
	./$(BIN)/normal 

runBaldwin: baldwin
	./$(BIN)/baldwin 

runLamarck: lamarck
	./$(BIN)/lamarck 

# Ejecutable sin optimización
$(BIN)/normal : $(OBJ)/normal.o $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o
	$(CXX) -o $(BIN)/normal $(OBJ)/normal.o -I$(INC) $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o

$(OBJ)/normal.o : $(SRC)/normal.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/normal.o $(SRC)/normal.cpp -I$(INC)

# Versión Baldwin
$(BIN)/baldwin : $(OBJ)/baldwin.o $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o
	$(CXX) -o $(BIN)/baldwin $(OBJ)/baldwin.o -I$(INC) $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o

$(OBJ)/baldwin.o : $(SRC)/baldwin.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/baldwin.o $(SRC)/baldwin.cpp -I$(INC)

# Versión Lamarck
$(BIN)/lamarck : $(OBJ)/lamarck.o $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o
	$(CXX) -o $(BIN)/lamarck $(OBJ)/lamarck.o -I$(INC) $(OBJ)/load-matrixes.o $(OBJ)/fitness.o $(OBJ)/poblacion-inicial.o $(OBJ)/seleccion.o $(OBJ)/cruzar.o $(OBJ)/mutar.o $(OBJ)/reemplazo.o

$(OBJ)/lamarck.o : $(SRC)/lamarck.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/lamarck.o $(SRC)/lamarck.cpp -I$(INC)

# Archivos con las diferenes funciones de carga de datos, selección ....

$(OBJ)/load-matrixes.o : $(SRC)/load-matrixes.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/load-matrixes.o $(SRC)/load-matrixes.cpp -I$(INC)

$(OBJ)/fitness.o : $(SRC)/fitness.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/fitness.o $(SRC)/fitness.cpp -I$(INC)

$(OBJ)/poblacion-inicial.o : $(SRC)/poblacion-inicial.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/poblacion-inicial.o $(SRC)/poblacion-inicial.cpp -I$(INC)

$(OBJ)/seleccion.o : $(SRC)/seleccion.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/seleccion.o $(SRC)/seleccion.cpp -I$(INC)

$(OBJ)/cruzar.o : $(SRC)/cruzar.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cruzar.o $(SRC)/cruzar.cpp -I$(INC)

$(OBJ)/mutar.o : $(SRC)/mutar.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/mutar.o $(SRC)/mutar.cpp -I$(INC)

$(OBJ)/reemplazo.o : $(SRC)/reemplazo.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/reemplazo.o $(SRC)/reemplazo.cpp -I$(INC)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
