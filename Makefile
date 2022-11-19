HOME = .
INCLUDE = $(HOME)/include
SRC = $(HOME)/src
BIN = $(HOME)/bin
OBJ = $(HOME)/obj

.PHONY: all clean crear_carpetas

all: crear_carpetas $(BIN)/scanner

crear_carpetas:
	-@mkdir -p $(BIN)

$(BIN)/scanner: $(SRC)/main.c $(SRC)/lex.yy.c $(SRC)/y.tab.c $(SRC)/y.tab.h
	gcc -o $@ $^

$(SRC)/y.tab.c $(SRC)/y.tab.h: $(SRC)/scanner.y
	bison -t -v -d -o $@ $(SRC)/scanner.y

$(SRC)/lex.yy.c: $(SRC)/scanner.l
	flex -o $@ $(SRC)/scanner.l

clean:
	-rm $(BIN)/*
	-rm $(OBJ)/*.o
	-rm $(SRC)/y.tab.c
	-rm $(SRC)/lex.yy.c
	# -rm $(SRC)/y.tab.h
	-rm $(SRC)/y.output
