HOME = .
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj

.PHONY: all clean crear_carpetas

all: crear_carpetas $(BIN)/scanner

crear_carpetas:
	-@mkdir -p $(BIN)

$(BIN)/scanner: $(OBJ)/semantic.o $(OBJ)/main.o $(OBJ)/y.tab.o
	gcc -o $@ $(OBJ)/semantic.o $(OBJ)/main.o $(OBJ)/y.tab.o

$(OBJ)/main.o: $(SRC)/main.c
	gcc -o $@ -c $(SRC)/main.c -I$(INCLUDE)

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	gcc -o $@ -c $(SRC)/y.tab.c -I$(INCLUDE)

$(SRC)/y.tab.c: $(SRC)/scanner.y $(SRC)/lex.yy.c
	bison -v -d -o $@ $(SRC)/scanner.y

$(SRC)/lex.yy.c: $(SRC)/scanner.l
	flex -o $@ $(SRC)/scanner.l

$(OBJ)/semantic.o: $(SRC)/semantic.c
	gcc -o $@ -c $(SRC)/semantic.c -I$(INCLUDE)

clean:
	-rm $(BIN)/*
	-rm $(OBJ)/*.o
	-rm $(SRC)/y.tab.c
	-rm $(SRC)/lex.yy.c
	-rm $(SRC)/y.tab.h
	-rm $(SRC)/y.output
