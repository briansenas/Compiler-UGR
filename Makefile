HOME = .
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj

.PHONY: all clean crear_carpetas

all: crear_carpetas $(BIN)/scanner

crear_carpetas:
	-@mkdir -p $(BIN)


$(BIN)/scanner: $(OBJ)/main.o $(OBJ)/y.tab.o
	g++ -g -o $@ $^

$(OBJ)/main.o: $(SRC)/main.c
	g++ -g -c -o $(OBJ)/main.o $(SRC)/main.c -I$(SRC)

$(BIN)/lexico: $(SRC)/lex.yy.c
	lex $^ -o $@ -I$(INCLUDE) -lfl

$(OBJ)/y.tab.o: $(SRC)/y.tab.c
	g++ -g -c -o $@ $(SRC)/y.tab.c -lfl -I$(SRC)

$(SRC)/y.tab.c: $(SRC)/scanner.l $(SRC)/lex.yy.c
	bison -v -d -o $@ $(SRC)/scanner.y

$(SRC)/lex.yy.c: $(SRC)/scanner.l
	flex -o $@ $(SRC)/scanner.l


#$(INCLUDE)/y.tab.h: $(SRC)/sintactico.y
#	yacc -d $^ -o $@

clean:
	-rm $(BIN)/*
	-rm $(OBJ)/*.o
	-rm $(SRC)/y.tab.c
	-rm $(SRC)/lex.yy.c
