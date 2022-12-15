#include "../include/scansemantic.h"
#include <string.h>

entradaTS ts[MAX_IN];
atributos ts_subprog[MAX_SUBPROG];
int line = 1;
unsigned long int TOPE = 0;
unsigned long int TOPE_SUBPROG=0;
int decvariable = 0;
int callSub = 0;
int decParam = 0;
int subProg = 0;
dtipo globaltipoDato= NA;
int globalLista = 0;
int nParam = 0;
int currentFunction = -1;

char* tipoAstring(dtipo tipo){

	char *tipo_str = malloc(255);
	if(!tipo_str)
		return NULL;

    tipo_str=strdup("Desconocido");

	if ( tipo == REAL ) {
        tipo_str=strdup("float");
	} else if (tipo == ENTERO) {
        tipo_str=strdup("int");
	} else if ( tipo == TIPOBOOL ) {
       tipo_str = strdup("bool");
	} else if ( tipo == CARACTER ) {
       tipo_str = strdup("char");
	}else if (tipo == TIPOCADENA){
	    tipo_str = strdup("string");
	}else if (tipo== NA){
 	    tipo_str = strdup("NA");
	}

	return tipo_str;
}

// Devuelve si el atributo es lista o no
int isList(atributos e){
	return e.lista;
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
	globalLista = value.lista;
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
		ts[TOPE].lista = in.lista;
		ts[TOPE].es_constante = in.es_constante;
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

	while (i >= 0 && !found /*&& ts[i].entrada != MARCA*/) {
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
			// printf("ADDING: %s - %d", e.nombre, e.lista);
			entradaTS newIn;
			newIn.entrada = VARIABLE;
			newIn.nombre = e.nombre;
			newIn.tipoDato= globaltipoDato;
			newIn.nParam = 0;
			newIn.lista = globalLista;
			newIn.es_constante = e.es_constante;
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
	inInitScope.lista = 0;
	inInitScope.es_constante = 0;
	inInitScope.nDim = 0;
	inInitScope.tamDimen1 = 0;
	inInitScope.tamDimen2 = 0;

	tsAddIn(inInitScope);

    // Se añaden a la tabla de símbolos los parámetros de la función como las
    // variableiables locales de ese bloque
	if(subProg>0){

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
				newIn.lista = ts[j].lista;
				newIn.es_constante = ts[j].es_constante;
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
	inSubProg.lista = e.lista;
	inSubProg.es_constante = e.es_constante;
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
		newIn.lista = globalLista;
		newIn.es_constante = e.es_constante;
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

int tsCheckList(atributos a){
	int index = tsSearchId(a);

	if(index<0)
		return 0;
	return ts[index].lista;
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
		res->lista = expr.lista;
		res->es_constante = res->es_constante;
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
		      printf("Semantic Error(%d): Id not found %s.\n", line, id.nombre);
		if(ts[index].entrada != FUNCION)
			printf("Semantic Error(%d): Id not found %s.\n", line, id.nombre);
	} else {
		//printf("El indice es %i", index);

		res->nombre = strdup(ts[index].nombre);
		res->tipoDato= ts[index].tipoDato;
		res->nDim = ts[index].nDim;
		res->lista = ts[index].lista;
		res->es_constante = ts[index].es_constante;
		res->tamDimen1 = ts[index].tamDimen1;
		res->tamDimen2 = ts[index].tamDimen2;

	}

}

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(atributos op, atributos o, atributos* res){
	int index = tsSearchId(o);
	if (!ts[index].lista && ts[index].tipoDato!=TIPOBOOL) {
		printf("Semantic Error(%d): Not operator expects logic expression.", line);
	}else if (ts[index].lista){
		if(op.attr==0){
			// Se esta aplicando el operador ! con una lista
			printf("Semantic Error(%d): Not operator expects logic expression.", line);
		}else{
			res->tipoDato= ts[index].tipoDato;
			res->lista = 0;
			res->es_constante = 1;
			res->nDim = 0;
			res->tamDimen1 = 0;
			res->tamDimen2 = 0;
		}
	}else{
		res->tipoDato= TIPOBOOL;
		res->nDim = 0;
		res->lista = 0;
		res->es_constante = 0;
		res->tamDimen1 = 0;
		res->tamDimen2 = 0;
	}
}

void tsCheckLeftList(atributos l, atributos a, atributos* res){

	int index = tsSearchId(l);
	//printf("\n%d\n",ts[index].lista);
	if(!ts[index].lista || a.tipoDato!=ENTERO){
		printf("Semantic Error(%d): El operador @ solo funciona con listas y enteros",line);
	}

	res->tipoDato = ts[index].tipoDato;
	res->lista = 0;
	res->es_constante = 1;
	res->nDim = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;
}


// Realiza la comprobación de la operación +, -
void tsOpSign(atributos op, atributos o, atributos* res){

	if ((o.tipoDato!= REAL && o.tipoDato!= ENTERO) || isList(o)) {
		printf("Semantic Error(%d): El operador espera una expresión de tipo entero o real ", line);
	}

	res->tipoDato= o.tipoDato;
	res->nDim = 0;
	res->lista = o.lista;
	res->es_constante = o.es_constante;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación +, - binaria
void tsOpAdditivo(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

	if (isList(o1) && isList(o2)){

		if(equalSize(o1,o2)){

			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		} else {
			printf("Semantic Error(%d): El tamaño debe ser el mismo. LS tiene %dx%d y RS tiene %dx%d",
							line, o1.tamDimen1,o1.tamDimen2,o2.tamDimen1,o2.tamDimen2);
			return;
		}

	} else {

		if (isList(o1) && !isList(o2)) {
			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		}

		if (!isList(o1) && isList(o2)){

			if (strcmp(op.nombre,"-")==0){

				printf("Semantic Error(%d): Operación no permitada.", line);
				return;

			} else {

				res->tipoDato= o2.tipoDato;
				res->nDim = o2.nDim;
				res->lista = o2.lista;
				res->es_constante = o2.es_constante;
				res->tamDimen1 = o2.tamDimen1;
				res->tamDimen2 = o2.tamDimen2;

			}

		}

	}

}


// Realiza la comprobación de la operación ++, --
void tsOpSignSign(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

	if (!isList(o1) && o2.tipoDato != ENTERO){
		printf("Semantic Error(%d): Operación no permitida", line);
		return;

	}


}

// Realiza la comprobación de la operación *, /, **, %
void tsOpMul(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

	if (isList(o1) && isList(o2)){
		if(equalSize(o1,o2)){
			res->tipoDato= o1.tipoDato;
			res->nDim = o1.nDim;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;
			res->tamDimen1 = o1.tamDimen1;
			res->tamDimen2 = o1.tamDimen2;

		} else {
			printf("Semantic Error(%d): El tamaño debe ser el mismo. LS tiene %dx%d y RS tiene %dx%d",
							line, o1.tamDimen1,o1.tamDimen2,o2.tamDimen1,o2.tamDimen2);
			return;
		}

	} else {
		if (isList(o1) && !isList(o2)) {
			if(op.attr != 3){
				res->tipoDato= o1.tipoDato;
				res->nDim = o1.nDim;
				res->lista = o1.lista;
				res->es_constante = o1.es_constante;
				res->tamDimen1 = o1.tamDimen1;
				res->tamDimen2 = o1.tamDimen2;
			}
			else{
				printf("Semantic Error(%d): Esa operación solo es válida con Listas\n",line);
			}

		}

		if (!isList(o1) && isList(o2)){
			if(op.attr != 3){
				res->tipoDato= o2.tipoDato;
				res->nDim = o2.nDim;
				res->lista = o2.lista;
				res->es_constante = o2.es_constante;
				res->tamDimen1 = o2.tamDimen1;
				res->tamDimen2 = o2.tamDimen2;
			}
			else{
				printf("Semantic Error(%d): Esa operación solo es válida con Listas\n",line);
			}
		}
	}
}

// Realiza la comprobación de la operación &&
void tsOpAnd(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->lista = 0;
	res->es_constante = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

void tsOpXOr(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->lista = 0;
	res->es_constante = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación ||
void tsOpOr(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}
	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->lista = 0;
	res->es_constante = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if (isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):El valor de una lista es ambiguo, no puede usar en un condicional.", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->lista = 0;
	res->es_constante = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;


}

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(atributos o1, atributos op, atributos o2, atributos* res){

	if (o1.tipoDato!= o2.tipoDato) {
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoAstring(o1.tipoDato),tipoAstring(o2.tipoDato));
		return;
	}

	if ((o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects ENTERO or REAL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->nDim = 0;
	res->lista = 0;
	res->es_constante = 0;
	res->tamDimen1 = 0;
	res->tamDimen2 = 0;

}


void TS_subprog_params(atributos atrib) {

	if ( TOPE_SUBPROG == MAX_SUBPROG ) {
		printf("ERROR: Tope de la pila de subprograma alcanzado. Demasiadas entradas en la tabla de símbolos auxiliar. Abortando compilación");
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

		printf("Semantic Error(%d)): Ese ID de FUNCION no se ha encontrado%s.\n", line, id.nombre);

    } else {
		if (nParam != ts[index].nParam) {
			printf("Semantic Error(%d):Número de parámetros inválidos.\n", line);
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
                        printf("Semantic Error(%d): El parámetro %s es de tipo %s pero se espera un tipo %s \n",
                                line ,ts[pos_limit].nombre, tipoAstring(ts[pos_limit].tipoDato),
                                tipoAstring(ts_subprog[TOPE_SUBPROG].tipoDato) );
                    }
                    pos_limit--;
                    TOPE_SUBPROG--;
                }
                currentFunction = index;
                //res->nombre = strdup(ts[index].nombre);
                res->tipoDato= ts[index].tipoDato;
                res->nDim = ts[index].nDim;
								res->lista = ts[index].lista;
								res->es_constante = ts[index].es_constante;
                res->tamDimen1 = ts[index].tamDimen1;
                res->tamDimen2 = ts[index].tamDimen2;
            }

		}
	}
	TOPE_SUBPROG = 0;
}

// Realiza la comprobación de cada parámetro de una función
void tsCheckParam(atributos param, int checkParam){

	int posParam = (currentFunction + ts[currentFunction].nParam) - (checkParam - 1);

	int error = ts[currentFunction].nParam - checkParam + 1;

	if (param.tipoDato!= ts[posParam].tipoDato) {
		printf("Semantic Error(%d): Parámetro tipoDato(%d) no es válido.\n", line, error);
		return;
	}

	if (param.nDim != ts[posParam].nDim || param.tamDimen1 != ts[posParam].tamDimen1  || param.tamDimen2 != ts[posParam].tamDimen2) {
		printf("Semantic Error(%d): Tamaño del parámetro (%d) no es válido.\n", line, error);
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
		printf("-lista %-10d",ts[j].lista);
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

	while(j <= TOPE_SUBPROG-1 && TOPE_SUBPROG>0) {
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
	printf("-lista %-10d",e.lista);
	printf("-nDim: %-4d", e.nDim);
	printf("-tamDimen1: %-4d", e.tamDimen1);
	printf("-tamDimen2: %-4d\n", e.tamDimen2);
	printf("-------------------------------\n");

}


int num_etiqueta = 0;
int num_var = 0;
int variable_main = 0;
int Many = 0;
int asignar = 0;
int principal = 0;
int cond = 0;
int isIf = 0;
FILE* MAIN;
FILE* FUNC;
int TS_ETIQ = 0;
etiquetas ts_etiq[50];

void addDesc(char* resultado){
    etiquetas etiq;
    etiq.etiqueta;
    etiq.etiqueta = strdup(resultado);
    ts_etiq[TS_ETIQ] = etiq;
    TS_ETIQ++;
}

void delDesc(){
    TS_ETIQ--;
}

void generaGOTO(char* etq){
    char* resultado = malloc(255); ;
    char* pattern = strdup("goto %s ;\n");
    snprintf(resultado,255,pattern,etq);
    cWriteCode(resultado);
    free(pattern);
    free(resultado);
}


char* generarEtiqueta(){
    char* resultado = malloc(255);
    snprintf(resultado,255,"etiqueta_%d",num_etiqueta);
    addDesc(resultado);
	num_etiqueta++;

	return resultado;
}

char* generarVariableTemporal() {
    char* resultado = malloc(255);
    snprintf(resultado,255,"tmp_%d",num_var);
    num_var++;
	return resultado;
}

void abrirArchivos(){
    MAIN = fopen("generado/main.c","w");
    FUNC = fopen("generado/dec_func.c","w");
	fputs("#include <stdio.h>\n",MAIN);
	fputs("#include <stdlib.h>\n", MAIN);
	fputs("#include <string.h>\n", MAIN);
	fputs("#include <stdbool.h>\n", MAIN);
	fputs("#include \"dec_func.c\"\n",MAIN);
	fputs("#include \"dec_data.c\"\n",MAIN);
    fputs("\n",MAIN);
	fputs("#include <stdio.h>\n",FUNC);
	fputs("#include <stdbool.h>\n", FUNC);
	fputs("#include \"dec_data.c\"\n",FUNC);
}

void cerrarArchivos(){
    fclose(MAIN);
    fclose(FUNC);
}

void cMarkOut(){
    if(subProg>0 || decParam)
        fputs("\n}\n",FUNC);
    else
        fputs("\n}\n",MAIN);
    variable_main = 0;
}

void cMarkIn(){
    if(subProg>0 || decParam)
        fputs("{\n",FUNC);
    else
        fputs("{\n",MAIN);
}

void tipoAtipoC(atributos var){

    char* resultado = malloc(255);

    if(var.lista)
        strcpy(resultado,"struct listade");
    else
        strcpy(resultado,"");
    dtipo tipo = var.tipoDato;
    if ( tipo == ENTERO ) {
		strcat(resultado, "int ");
	} else if ( tipo == REAL ) {
		strcat(resultado, "float ");
	} else if ( tipo == TIPOBOOL ) {
		strcat(resultado, "bool ");
	} else if ( tipo == CARACTER ) {
		strcat(resultado, "char ");
	}


    if(subProg>0|| decParam)
        fputs(resultado,FUNC);
    else
        fputs(resultado,MAIN);

    free(resultado);
}

void addNewLine(){
    if(subProg>0 || decParam)
        fputs("\n",FUNC);
    else
        fputs("\n",MAIN);
}

void addPYC(){
    if(subProg>0 || decParam)
        fputs(";",FUNC);
    else
        fputs(";",MAIN);
}

void addCOMMA(){
    if(subProg>0 || decParam)
        fputs(",",FUNC);
    else
        fputs(",",MAIN);
}
void addPAR_A(){
    if(subProg>0 || decParam)
        fputs("(",FUNC);
    else
        fputs("(",MAIN);
}

void addPAR_C(){
    if(subProg>0 || decParam)
        fputs(")",FUNC);
    else
        fputs(")",MAIN);
}

void addASSIGN(){
    if(subProg>0 || decParam)
        fputs("=",FUNC);
    else
        fputs("=",MAIN);
}

char* getADD(int a){
    char* tmp = malloc(1);
    if(a==0)
        tmp[0] = '+';
    else
        tmp[0] = '-';
    return tmp;
}

void addADD(atributos a){
    if(subProg>0 || decParam)
        fputs(getADD(a.attr),FUNC);
    else
        fputs(getADD(a.attr),MAIN);
}

int tsSearchParam(atributos a) {
    int tope = TOPE - 1;
    int found = 0;
    while(tope>0 && !found){
		if(strcmp(a.nombre, ts[tope].nombre) == 0) {
            found = 1;
        }else{
            tope--;
        }
    }

    if(!found)
        tope = -1;

    return tope;
}

void cWriteIdent(atributos a){
    int index = -1;
    if(decvariable==1)
        index = tsSearchId(a);
    if(decParam)
        index = tsSearchParam(a);

    char* tmp = malloc(255);
    if(index<0)
        strcpy(tmp,generarVariableTemporal());
    else
        strcpy(tmp,ts[index].nombre);

    if(subProg>0|| decParam)
        fputs(tmp,FUNC);
    else
        fputs(tmp,MAIN);

    free(tmp);
}

void cWriteName(atributos a){
    if(subProg>0 || decParam)
        fputs(a.nombre,FUNC);
    else
        fputs(a.nombre,MAIN);
}

void cWriteCode(char* code){
    if(subProg>0 || decParam)
        fputs(code,FUNC);
    else
        fputs(code,MAIN);
}

void generaCodigoVariableTemporal(atributos a, atributos* res){
    tipoAtipoC(a);
    cWriteCode(res->nombre);
    addPYC();
    addNewLine();
}
void generaCodigoAsignacion(atributos a, atributos b){
    decvariable=1;
    cWriteIdent(a);
    addASSIGN();
    cWriteName(b);
    addPYC();
    addNewLine();
    decvariable=2;
}
void generaCodigoOpAditivo(atributos a, atributos op, atributos b, atributos* res){
    res->codigo = malloc(255);
    char* _code;
    if(op.attr==0)
       _code = strdup("%s = %s + %s;\n");
    else
       _code = strdup("%s = %s - %s;\n");
    snprintf(res->codigo,255,_code,res->nombre, a.nombre, b.nombre);
    cWriteCode(res->codigo);
    free(_code);
}

void generaSigno(atributos op, atributos b, atributos* res){
    res->nombre = malloc(255);
    char* _code;
    if(op.attr==0)
       _code = strdup("+%s");
    else
       _code = strdup("-%s");
    snprintf(res->nombre,255,_code,b.nombre);
    free(_code);
}

void generaCodigoOpMultiplicativo(atributos a, atributos op, atributos b, atributos* res){
    res->codigo = malloc(255);
    char* _code;
    if(op.attr==0)
       _code = strdup("%s = %s * %s;\n");
    else if(op.attr==1)
       _code = strdup("%s = %s / %s;\n");
    else if(op.attr==2)
       _code = strdup("%s = %s %% %s;\n");
    else if(op.attr==3)
       _code = strdup("%s = %s ** %s;\n");
    snprintf(res->codigo,255,_code,res->nombre, a.nombre, b.nombre);
    cWriteCode(res->codigo);
    free(_code);
}

void generaCodigoOpRelacion(atributos a, atributos op, atributos b, atributos* res){
    res->codigo = malloc(255);
    char* _code;
    if(op.attr==0)
       _code = strdup("%s = %s < %s;\n");
    else if(op.attr==1)
       _code = strdup("%s = %s > %s;\n");
    else if(op.attr==2)
       _code = strdup("%s = %s <= %s;\n");
    else if(op.attr==3)
       _code = strdup("%s = %s >= %s;\n");
    snprintf(res->codigo,255,_code,res->nombre, a.nombre, b.nombre);
    cWriteCode(res->codigo);
    free(_code);
}

void generaCodigoReturn(atributos a){
    a.codigo = malloc(255);
    snprintf(a.codigo,255,"return %s;\n",a.nombre);
    cWriteCode(a.codigo);
    free(a.codigo);
}

void generaCodigo(char* pattern, char* a, char* b, char* c){
    char* resultado = malloc(255);
    snprintf(resultado,255,pattern,a,b,c);
    cWriteCode(resultado);
    free(resultado);
}

void generaCodigoUnario(atributos op, atributos a, atributos* res){
    res->codigo = malloc(255);
    char* _code ;

    if(op.attr==0)
       _code = strdup("%s = !%s;\n");
    else if(op.attr==1)
       _code = strdup("%s = getLongitudLista%s(%s);\n");
    else if(op.attr==2)
       _code = strdup("%s = getActualLista%s(%s);\n");

    snprintf(res->codigo,255,_code,res->nombre, tipoAstring(a.tipoDato),a.nombre);
    cWriteCode(res->codigo);
    free(_code);
}

void generaCodigoSi(atributos* a, atributos exp){
    char* _code = malloc(255);
    char* pattern = strdup("if(!%s) goto %s;\n");
    a->etiq1 = generarEtiqueta();
    snprintf(_code,255,pattern,exp.nombre,a->etiq1);
    cWriteCode(_code);
    free(_code);
    free(pattern);
}

char* tipoAprintf(dtipo tipo) {
    char* resultado;

	if ( tipo == ENTERO ) {
		resultado = strdup( "%d");
	} else if ( tipo == REAL ) {
		resultado = strdup( "%f");
	} else if ( tipo == TIPOBOOL ) {
		resultado = strdup( "%d");
	} else if ( tipo == CARACTER ) {
		resultado = strdup( "%c");
	} else if ( tipo == TIPOCADENA ) {
		resultado = strdup( "%s");
    }

	return resultado;
}

void generarE(char* E_S){
    int i = 0;
    char* res = malloc(255);
    strcpy(res,E_S);
    while(i<TOPE_SUBPROG){
        strcat(res,tipoAprintf(ts_subprog[i].tipoDato));
        if(i<TOPE_SUBPROG-1)
            strcat(res,", ");
        i++;
    }
    i=0;
    strcat(res,"\",");
    while(i<TOPE_SUBPROG){
				strcat(res,"&");
        strcat(res,ts_subprog[i].nombre);
        if(i<TOPE_SUBPROG-1)
            strcat(res,", ");
        i++;
    }
    strcat(res,");\n");
    cWriteCode(res);
    TOPE_SUBPROG = 0;
    free(res);
}

void generarS(char* E_S){
    int i = 0;
    char* res = malloc(255);
    strcpy(res,E_S);
    while(i<TOPE_SUBPROG){
        strcat(res,tipoAprintf(ts_subprog[i].tipoDato));
        i++;
    }
    i=0;
    strcat(res,"\",");
    while(i<TOPE_SUBPROG){
        strcat(res,ts_subprog[i].nombre);
        if(i<TOPE_SUBPROG-1)
            strcat(res,", ");
        i++;
    }
    strcat(res,");\n");
    cWriteCode(res);
    TOPE_SUBPROG = 0;
    free(res);
}


char* generarFuncion(char* nombre){
    int i = 0;
    char* res = malloc(255);
    i=0;
	strcpy(res,nombre);
    strcat(res,"(");
    while(i<TOPE_SUBPROG){
        strcat(res,ts_subprog[i].nombre);
        if(i<TOPE_SUBPROG-1)
            strcat(res,", ");
        i++;
    }
    strcat(res,");\n");

	return res;
}

void cWriteLabel(char* etiq1){
    char* etq = malloc(255);
    strcpy(etq,etiq1);
    strcat(etq,":\n");
    cWriteCode(etq);
    free(etq);
}

void cWriteFunc(atributos in, atributos* res){
    int index = tsSearchName(in);
    atributos a;
    a.lista = ts[index].lista;
    a.nombre = ts[index].nombre;
    a.tipoDato = ts[index].tipoDato;
    generaCodigoVariableTemporal(a,res);
    char* resultado = malloc(255);
    char* pattern = strdup("%s = %s");
    snprintf(resultado,255,pattern,res->nombre,generarFuncion(in.nombre));
    cWriteCode(resultado);
    free(resultado);
    free(pattern);
}

void moverCursor(atributos a ){
    char* pattern;
    if(a.attr==0){
    pattern = strdup("retrocederLista%s(&%s);\n");
    }else if(a.attr==1){
    pattern = strdup("avanzarLista%s(&%s);\n");
    }else{
    pattern = strdup("irAPosicion%s(&%s,0);\n");
    }
    char* code = malloc(255);
    snprintf(code,255,pattern,tipoAstring(a.tipoDato),a.nombre);
    cWriteCode(code);
    free(pattern);
    free(code);
}

void generaCreacionLista(atributos a){
    int i = 0;
    char* res = malloc(255);
    i=TOPE_SUBPROG-1;
    char* var_name = malloc(255);
    snprintf(var_name, 255, "listade%s", tipoAstring(a.tipoDato));
    snprintf(res,255,"struct %s %s= %s_default;\n",var_name,a.nombre,var_name);
    cWriteCode(res);
    var_name = strdup(a.nombre);
    char* pattern = strdup("insertar%s(&%s,%s);\n");
    while(i>=0){
        snprintf(res,255,pattern,tipoAstring(a.tipoDato),var_name,ts_subprog[i].nombre);
        cWriteCode(res);
        i--;
    }
    TOPE_SUBPROG = 0;
    free(var_name);
    free(pattern);
    free(res);
}
