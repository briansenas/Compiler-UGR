#include "../include/scansemantic.h"
#include <string.h>

entradaTS ts[MAX_IN];
atributos ts_subprog[MAX_SUBPROG];
int line = 1;
unsigned long int TOPE = 0;
unsigned long int TOPE_SUBPROG=0;
int decvariable = 0;
int decParam = 0;
int decfuncion = 0;
int subProg = 0;
dtipo globaltipoDato= NA;
int nParam = 0;
int currentFunction = -1;
int aux = 0;
int callSub = 0;

char* tipoAstring(dtipo tipo){

	char tipo_str[255] = "desconocido";

	if ( tipo == REAL ) {
        strncpy(tipo_str,"real",255);
	} else if (tipo == ENTERO) {
        strncpy(tipo_str,"entero",255);
	} else if ( tipo == TIPOBOOL ) {
        strncpy(tipo_str,"booleano",255);
	} else if ( tipo == CARACTER ) {
        strncpy(tipo_str,"caracter",255);
	}

    printf("\n%s\n",tipo_str);

	return tipo_str;
}

// Devuelve si el atributo es lista o no
int isList(atributos e){

    return (e.nDim!=0);
}

// Devuelve si los dos posibles arrays que recibe tienen el mismo tamaño
int equalSize(atributos e1, atributos e2){

    return (e1.nDim == e2.nDim &&
        e1.tamDimen1 == e2.tamDimen1 &&
        e1.tamDimen2 == e2.tamDimen2);

}

// Guarda el tipoDatode la variableiable
int setType(atributos value){
    globaltipoDato= value.tipoDato;
}

///////////////////////////////////////////////////////////////////////////////
// Tabla de Símbolos
//

// Inserta una in en la tabla de símbolos
int tsAddIn(entradaTS in){

    // Si se tienen más entradas de las que puede alojar la tabla de símbolos
    // dará un error, si no, se inserta
	if(TOPE < MAX_IN) {

		ts[TOPE].entrada=in.entrada;
		ts[TOPE].nombre=in.nombre;
		ts[TOPE].tipoDato=in.tipoDato;
		ts[TOPE].nParam=in.nParam;
		ts[TOPE].nDim=in.nDim;
		ts[TOPE].tamDimen1=in.tamDimen1;
		ts[TOPE].tamDimen2=in.tamDimen2;

        // Se aumenta el contador de entradas
		TOPE++;

        // Se muestra la tabla de símbolos por pantalla
		//printTS();

		return 1;

	} else {

		printf("Semantic Error(%d): Stack overflow", line);

		return 0;

	}

}

// Elimina una in de la tabla de símbolos
int tsDelIn(){

    // Si la tabla de símbolos tiene alguna in puede eliminar la última
    if(TOPE > 0){

		TOPE--;
		return 1;

	}else{

		printf("Semantic Error(%d): Empty table", line);
		return 0;

	}

}

// Elimina las entradas de la tabla de símbolos hasta la MARCA de tope
void tsCleanIn(){

    while(ts[TOPE-1].entrada != MARCA && TOPE > 0){
		TOPE--;
	}
	if (ts[TOPE-1].entrada == MARCA) {
		TOPE--;
	}

    /*
    if (ts[TOPE-1].entrada == MARCA) {
        while(ts[TOPE-1].entrada != FUNCION && TOPE > 0){
    		TOPE--;
    	}
        TOPE--;
	}
    */
    // printTS();

}

// Busca una entrada según el id
int tsSearchId(atributos e){

    int i = TOPE - 1;
	int found = 0;

	while (i > 0 && !found /*&& ts[i].entrada != MARCA*/) {
		if (ts[i].entrada == VARIABLE && strcmp(e.nombre, ts[i].nombre) == 0) {
			found = 1;
		} else{
			i--;
		}
	}

	if(!found) {
		printf("Semantic Error(%d): Identifier not declared: %s\n", line, e.nombre);
		return -1;
	} else {
		return i;
	}

}

// Busca una in según el nombre
int tsSearchName(atributos e){

    int i = TOPE - 1;
	int found = 0;


	while (i > 0 && !found /*&& ts[i].entrada != MARCA*/) {
        // printf("\n[%s - %s]\n", e.nombre, ts[i].nombre);
		if (ts[i].entrada == FUNCION && strcmp(e.nombre, ts[i].nombre) == 0) {
			found = 1;
		} else{
			i--;
		}
	}

	if(!found) {
		printf("Semantic Error(%d): Ident not declared: %s\n", line, e.nombre);
		return -1;
	} else {
		return i;
	}

}

// Añade un id
void tsAddId(atributos e){

    // Para añadir un id a la pila no se puede haber llegado al tope,
    // el id no puede existir y se deben estar declarando variableiables
	int j = TOPE-1;
	int found = 0;

	if(j > 0 && decvariable == 1){
		// Se obtiene la posición de la MARCA del bloque
		while((ts[j].entrada != MARCA) && (j >= 0) && !found){

			if(strcmp(ts[j].nombre, e.nombre) != 0){

				j--;

			} else{

				found = 1;
				printf("Semantic Error(%d): Identifier already exists: %s\n", line, e.nombre);

	 		}

		}

		// Si no se ha encontrado significa que no existe, por lo que se añade
        // a la pila
		if(!found) {
			entradaTS newIn;
			newIn.entrada = VARIABLE;
			newIn.nombre = e.nombre;
			newIn.tipoDato= globaltipoDato;
			newIn.nParam = 0;
			newIn.nDim=e.nDim;
			newIn.tamDimen1=e.tamDimen1;
			newIn.tamDimen2=e.tamDimen2;
			tsAddIn(newIn);

		}

	}
}

// Añade una MARCA de tope
void tsAddMark(){

    entradaTS inInitScope;

	inInitScope.entrada = MARCA;
	inInitScope.nombre = "{";
	inInitScope.tipoDato= NA;
	inInitScope.nParam = 0;
	inInitScope.nDim = 0;
	inInitScope.tamDimen1 = 0;
	inInitScope.tamDimen2 = 0;

	tsAddIn(inInitScope);

    // Se añaden a la tabla de símbolos los parámetros de la función como las
    // variableiables locales de ese bloque
	if(subProg == 1){

		int j = TOPE - 2, mark = 0, funct = 0;

		while(j > 0 && ts[j].entrada == PARAMETRO_FORMAL){

			/*printf("\n\n");
			printIn(j);
			printf("\n\n");*/

			if(ts[j].entrada == PARAMETRO_FORMAL) {

				entradaTS newIn;
				newIn.entrada = VARIABLE;
				newIn.nombre = ts[j].nombre;
				newIn.tipoDato= ts[j].tipoDato;
				newIn.nParam = ts[j].nParam;
				newIn.nDim = ts[j].nDim;
				newIn.tamDimen1 = ts[j].tamDimen1;
				newIn.tamDimen2 = ts[j].tamDimen2;
				tsAddIn(newIn);

			}

			j--;

		}

	}

}

// Añade una in de subprograma
void tsAddSubprog(atributos e){

    entradaTS inSubProg;
    //printf("\nAddingSubProg:%s\n",e.nombre);
	inSubProg.entrada = FUNCION;
	inSubProg.nombre = e.nombre;
	inSubProg.nParam = 0;
	inSubProg.nDim = 0;
	inSubProg.tamDimen1 = 0;
	inSubProg.tamDimen2 = 0;
	inSubProg.tipoDato= e.tipoDato;

	currentFunction = TOPE;
	tsAddIn(inSubProg);

}

// Añade una in de param PARAMETRO_FORMALAL
void tsAddParam(atributos e){

    int j = TOPE - 1, found = 0;

	while((j != currentFunction)  && (!found) ){

		if(strcmp(ts[j].nombre, e.nombre) != 0) {

			j--;

		} else{

			found = 1;
			printf("Semantic Error(%d): Param name already exists: %s\n", line, e.nombre);

        }

	}

	if(!found) {

		entradaTS newIn;
		newIn.entrada = PARAMETRO_FORMAL;
		newIn.nombre = e.nombre;
		newIn.tipoDato= globaltipoDato;
		newIn.nParam = 0;
		newIn.nDim = e.nDim;
		newIn.tamDimen1 = e.tamDimen1;
		newIn.tamDimen2 = e.tamDimen2;
		tsAddIn(newIn);

	}

}

// Actualiza el número de parámetros de la función
void tsUpdateNparam(atributos e){

    ts[currentFunction].nParam = nParam;
	ts[currentFunction].nDim=e.nDim;
	ts[currentFunction].tamDimen1=e.tamDimen1;
	ts[currentFunction].tamDimen2=e.tamDimen2;

}

//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Analizador Semántico
//

// Devuelve la in que sea función más cercana
int tsGetNextfuncion(){

    int i = TOPE - 1;
	int found = 0;

	while (i >=0 && !found) {
		if (ts[i].entrada == MARCA) {
			found++;
		} else {
			i--;
		}

	}
    found = 0;
    while(i>=0 && !found){
        if(ts[i].entrada==FUNCION){
            found++;
        }
        else{
            i--;
        }
    }

	if(!found) {
		return -1;
	} else {
		return i;
	}

}

// Comprueba si el tipoDatode la expresión coincide con lo que devuelve la función
void tsCheckReturn(atributos expr, atributos* res){

    int index = tsGetNextfuncion();
    //printf("\nFOUND_FUNCTION:%s\n",ts[index].nombre);
    //printTS();
	if (index > -1) {
		//printf("Ha encontrado una FUNCION en la pila\n");

		if (expr.tipoDato!= ts[index].tipoDato) {
			printf("Semantic Error(%d): Return of type %s does not equal return type %s of function %s.\n",
                    line, tipoAstring(expr.tipoDato),tipoAstring(ts[index].tipoDato),ts[index].nombre);
			return;
		}

		atributos tmp;
		tmp.nDim = ts[index].nDim;
		tmp.tamDimen1 = ts[index].tamDimen1;
		tmp.tamDimen2 = ts[index].tamDimen2;

		if (!equalSize(expr,tmp)) {
			printf("Semantic Error(%d): Return expresion not same size than return of function %s\n",
                    line,ts[index].nombre);
			return;
		}

		res->tipoDato = expr.tipoDato;
		res->nDim = expr.nDim;
		res->tamDimen1 = expr.tamDimen1;
		res->tamDimen2 = expr.tamDimen2;

	} else {
		printf("Semantic Error(%d-%d): res not declared inside a function.\n", line, index);
		return;
	}
}

// Devuelve el identificar
void tsGetId(atributos id, atributos* res){

    int index = tsSearchId(id);

	if(index==-1) {
        if(ts[index].entrada != FUNCION)
		      printf("\nSemantic Error(%d): Id not found %s.\n", line, id.nombre);
	} else {
		//printf("El indice es %i", index);

		res->nombre = strdup(ts[index].nombre);
		res->tipoDato= ts[index].tipoDato;
		res->nDim = ts[index].nDim;
		res->tamDimen1 = ts[index].tamDimen1;
		res->tamDimen2 = ts[index].tamDimen2;

	}

}

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(atributos op, atributos o, atributos* res){

    if (o.tipoDato!= TIPOBOOL || isList(o)) {
		printf("Semantic Error(%d): Not operator expects logic expression.", line);
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación +, -
void tsOpSign(atributos op, atributos o, atributos* res){

    if ((o.tipoDato!= REAL && o.tipoDato!= ENTERO) || isList(o)) {
		printf("Semantic Error(%d): Operator expects integer or REAL expression.", line);
	}

	res->tipoDato= o.tipoDato;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación +, - binaria
void tsOpAdditivo(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): Invalid tipoDato in op. Operation must be with real or entero", line);
		return;
	}

	if (isList(o1) && isList(o2)){

		if(equalSize(o1,o2)){

			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		} else {
            printf("Semantic Error(%d): Size arrays must be same. Index 0 has size %dx%d and index 1 has size %dx%d",
                    line, o1.tamDimen1,o1.tamDimen2,o2.tamDimen1,o2.tamDimen2);
			return;
		}

	} else {

		if (isList(o1) && !isList(o2)) {
			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		}

		if (!isList(o1) && isList(o2)){

			if (strcmp(op.nombre,"-")==0){

				printf("Semantic Error(%d): Operation not allowed.", line);
				return;

			} else {

				res->tipoDato= o2.tipoDato;
				res->nDim = o2.nDim;
				res->tamDimen1 = o2.tamDimen1;
				res->tamDimen2 = o2.tamDimen2;

			}

		}

	}

}


// Realiza la comprobación de la operación ++, --
void tsOpSignSign(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): Invalid tipoDato in op. Operation must be with real or entero", line);
		return;
	}

	if (isList(o1) && isList(o2)){

		if(equalSize(o1,o2)){

			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		} else {

            printf("Semantic Error(%d): Size arrays must be same. Index 0 has size %dx%d and index 1 has size %dx%d",
                    line, o1.tamDimen1,o1.tamDimen2,o2.tamDimen1,o2.tamDimen2);
			return;

		}

	} else {

		if (!isList(o1) || !isList(o2)) {
				printf("Semantic Error(%d): Operation not allowed.", line);
				return;
			}

		}

}

// Realiza la comprobación de la operación *, /
void tsOpMul(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): Invalid tipoDato in op. Operation must be with real or entero", line);
		return;
	}

	if (isList(o1) && isList(o2)){

		if(equalSize(o1,o2)){

			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		} else {

            printf("Semantic Error(%d): Size arrays must be same. Index 0 has size %dx%d and index 1 has size %dx%d",
                    line, o1.tamDimen1,o1.tamDimen2,o2.tamDimen1,o2.tamDimen2);
			return;

		}

	} else {

		if (isList(o1) && !isList(o2)) {

			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		}

		if (!isList(o1) && isList(o2)){

			if (strcmp(op.nombre,"-")==0){

				printf("Semantic Error(%d): Operation not allowed.", line);
				return;

			} else {

				res->tipoDato= o2.tipoDato;
				res->nDim = o2.nDim;
				res->tamDimen1 = o2.tamDimen1;
				res->tamDimen2 = o2.tamDimen2;

			}

		}

	}

}

// Realiza la comprobación de la operación &&
void tsOpAnd(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}

	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid tipoDatoin op. Both must be same. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

void tsOpXOr(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}
	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid tipoDatoin op. Both must be same. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación ||
void tsOpOr(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}
	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid tipoDatoin op. Both must be same. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}
	if (isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid tipoDatoin op. Both must be same. Expects ENTERO or REAL.", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(atributos o1, atributos op, atributos o2, atributos* res){

    if (o1.tipoDato!= o2.tipoDato) {
	    printf("Semantic Error(%d): Expressions must be equals types. %s does not match %s",
                line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
  		return;
  	}
	if ((o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Invalid tipoDatoin op. Both must be same. Expects ENTERO or REAL.", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}


void TS_subprog_params(atributos atrib) {

	if ( TOPE_SUBPROG == MAX_SUBPROG ) {
		printf("ERROR: Tope de la pila alcanzado. Demasiadas entradas en la tabla de símbolos. Abortando compilación");
	} else {
		ts_subprog[TOPE_SUBPROG] = atrib;

		TOPE_SUBPROG++;

	}

    //printSPTS();

}

// Realiza la comprobación de la llamada a una función
void tsFunctionCall(atributos id, atributos* res){

    int index = tsSearchName(id);
    //printf("\nFOUND_FUNCTION:%s\n",ts[index].nombre);

	if(index==-1) {

		currentFunction = -1;

		printf("\nSemantic Error(%d)): FUNCION: Id not found %s.\n", line, id.nombre);

    } else {
		if (nParam != ts[index].nParam) {
			printf("Semantic Error(%d): Number of param not valid.\n", line);
		}
        else {
            int pos_limit = index + ts[index].nParam;
            if(ts[index].nParam != TOPE_SUBPROG){
                printf("Semantic Error(%d): La funcion %s necesita %d parámetros y se han proporcionado %ld\n", line, ts[index].nombre, ts[index].nParam, TOPE_SUBPROG);
            }else{
                TOPE_SUBPROG--;
                while(TOPE_SUBPROG>0){
                    entradaTS tempTS;
                    tempTS.tipoDato = ts_subprog[TOPE_SUBPROG].tipoDato;
                    if(!ts_subprog[TOPE_SUBPROG].es_constante){
                        tempTS = ts[tsSearchName(ts_subprog[TOPE_SUBPROG])];
                    }

                    if(ts[pos_limit].tipoDato != tempTS.tipoDato){
                        printf("\nSemantic Error(%d): El parámetro %s es de tipo %s pero se espera un tipo %s \n",
                                line ,ts[pos_limit].nombre, tipoAstring(ts[pos_limit].tipoDato),
                                tipoAstring(ts_subprog[TOPE_SUBPROG].tipoDato) );
                    }
                    pos_limit--;
                    TOPE_SUBPROG--;
                }
                currentFunction = index;
                res->nombre = strdup(ts[index].nombre);
                res->tipoDato= ts[index].tipoDato;
                res->nDim = ts[index].nDim;
                res->tamDimen1 = ts[index].tamDimen1;
                res->tamDimen2 = ts[index].tamDimen2;
            }

		}
	}
}

// Realiza la comprobación de cada parámetro de una función
void tsCheckParam(atributos param, int checkParam){

    int posParam = (currentFunction + ts[currentFunction].nParam) - (checkParam - 1);

	int error = ts[currentFunction].nParam - checkParam + 1;

	if (param.tipoDato!= ts[posParam].tipoDato) {
		printf("Semantic Error(%d): Param tipoDato(%d) not valid.\n", line, error);
		return;
	}

	if (param.nDim != ts[posParam].nDim || param.tamDimen1 != ts[posParam].tamDimen1  || param.tamDimen2 != ts[posParam].tamDimen2) {
		printf("Semantic Error(%d): Size param (%d) not valid.\n", line, error);
		return;
	}

}

//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Visualización
//

// Muestra una in de la tabla de símbolos
void printIn(int row){

    entradaTS e = ts[row];
	printf("\n\nTipo Entrada: %d\nLexema: %s\nTipo Dato: %d\nNum Parametros: %d\nDimensiones[i][j]: %d[%d][%d]\n",
		e.entrada, e.nombre, e.tipoDato, e.nParam, e.nDim, e.tamDimen1, e.tamDimen2);

}

// Muestra el tipoDatode la in
void printInType(tipoEntrada tipoDato){



}

// Muestra el tipoDatodel dato recibido
void printDataType(dtipo tipoDato){



}

// Muestra la tabla de símbolos
void printTS(){

    int j = 0;
	char *t, *e;

	printf("--------------------------------\n");
	while(j <= TOPE-1) {
		if(ts[j].entrada == 0) { e = "marca"; }
		if(ts[j].entrada == 1) { e = "funcion"; }
		if(ts[j].entrada == 2) { e = "variable"; }
		if(ts[j].entrada == 3) { e = "parametro_formal"; }

		if(ts[j].tipoDato== 0) { t = "entero"; }
		if(ts[j].tipoDato== 1) { t = "real"; }
		if(ts[j].tipoDato== 2) { t = "caracter"; }
		if(ts[j].tipoDato== 3) { t = "booleano"; }
		if(ts[j].tipoDato== 4) { t = "lista"; }
		if(ts[j].tipoDato== 5) { t = "desconocido"; }
		if(ts[j].tipoDato== 6) { t = "na"; }
		printf("----ELEMENTO %d-----------------\n", j);
		printf("-Entrada: %-12s", e);
		printf("-Lexema: %-12s", ts[j].nombre);
		printf("-type: %-10s", t);
		printf("-nParam: %-4d", ts[j].nParam);
		printf("-nDim: %-4d", ts[j].nDim);
		printf("-tamDimen1: %-4d", ts[j].tamDimen1);
		printf("-tamDimen2: %-4d\n", ts[j].tamDimen2);
		j++;
	}
	printf("--------------------------------\n");

}

void printSPTS(){

    int j = 0;
	char *t, *e;

	printf("\n--------------------------------\n");
	while(j <= TOPE_SUBPROG-1) {
		if(ts_subprog[j].tipoDato== 0) { t = "entero"; }
		if(ts_subprog[j].tipoDato== 1) { t = "real"; }
		if(ts_subprog[j].tipoDato== 2) { t = "caracter"; }
		if(ts_subprog[j].tipoDato== 3) { t = "booleano"; }
		if(ts_subprog[j].tipoDato== 4) { t = "lista"; }
		if(ts_subprog[j].tipoDato== 5) { t = "desconocido"; }
		if(ts_subprog[j].tipoDato== 6) { t = "na"; }
		printf("----ELEMENTO %d-----------------\n", j);
		printf("-type: %-10s", t);
		j++;
	}
	printf("--------------------------------\n");

}

// Muestra un atributo recibido
void printAttr(atributos e, char *msg){

    char *t;


	if(e.tipoDato== 0) { t = "entero"; }
	if(e.tipoDato== 1) { t = "real"; }
	if(e.tipoDato== 2) { t = "caracter"; }
	if(e.tipoDato== 3) { t = "booleano"; }
	if(e.tipoDato== 4) { t = "lista"; }
	if(e.tipoDato== 5) { t = "desconocido"; }
	if(e.tipoDato== 6) { t = "na"; }
	printf("------%s-------------------------\n", msg);
	printf("-Atributos: %-4d", e.attr);
	printf("-Lexema: %-12s", e.nombre);
	printf("-type: %-10s", t);
	printf("-nDim: %-4d", e.nDim);
	printf("-tamDimen1: %-4d", e.tamDimen1);
	printf("-tamDimen2: %-4d\n", e.tamDimen2);
	printf("-------------------------------\n");

}
