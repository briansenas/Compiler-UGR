#define _GNU_SOURCE
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

	char *tipo_str = NULL ;
    tipo_str=strealloc(tipo_str,"Desconocido");

	if ( tipo == REAL ) {
        tipo_str=strealloc(tipo_str,"float");
	} else if (tipo == ENTERO) {
        tipo_str=strealloc(tipo_str,"int");
	} else if ( tipo == TIPOBOOL ) {
       tipo_str =strealloc(tipo_str ,"bool");
	} else if ( tipo == CARACTER ) {
       tipo_str =strealloc(tipo_str, "char");
	}else if (tipo == TIPOCADENA){
	    tipo_str =strealloc(tipo_str ,"string");
	}else if (tipo== NA){
 	    tipo_str =strealloc(tipo_str, "NA");
	}

	return tipo_str;
}

// Devuelve si el atributo es lista o no
int isList(atributos e){
	return e.lista;
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

	tsAddIn(inInitScope);

    // Se añaden a la tabla de símbolos los parámetros de la función como las
    // variableiables locales de ese bloque
	if(subProg>0){

		int j = TOPE - 2, mark = 0, funct = 0;

		while(j > 0 && ts[j].entrada == PARAMETRO_FORMAL){

			if(ts[j].entrada == PARAMETRO_FORMAL) {

				entradaTS newIn;
				newIn.entrada = VARIABLE;
				newIn.nombre = ts[j].nombre;
				newIn.tipoDato= ts[j].tipoDato;
				newIn.nParam = ts[j].nParam;
				newIn.lista = ts[j].lista;
				newIn.es_constante = ts[j].es_constante;
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
	inSubProg.lista = e.lista;
	inSubProg.es_constante = e.es_constante;
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
		newIn.lista = globalLista;
		newIn.es_constante = e.es_constante;
		tsAddIn(newIn);

	}

}

// Actualiza el número de parámetros de la función
void tsUpdateNparam(atributos e){
	ts[currentFunction].nParam = nParam;
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

void checkTypes(atributos a, atributos b){
    int index = tsSearchId(a);
    if(index<0){
			printf("Semantic Error(%d): Identifier not found for assignment.\n",line);
    }else if(ts[index].tipoDato != b.tipoDato){
        char* tipoA = tipoAstring(ts[index].tipoDato);
        char* tipoB = tipoAstring(b.tipoDato);
        printf("Semantic Error(%d): La variable %s es de tipo %s pero se asigna el tipo %s \n",
                line, ts[index].nombre, tipoA,tipoB);
        free(tipoA);
        free(tipoB);
    }
}

void generaCodigoInicializacion(atributos a){
    decvariable=1;
    cWriteIdent(a);
    addChar('=');
    if(a.tipoDato==COMPLEJO){
        char* _pattern = malloc(255);
        strcpy(_pattern,"setComplex(");
        int i = 0;
        if(TOPE_SUBPROG!=2){
			printf("Semantic Error(%d): Wrong number of parameters\n",line);
        }else{
            while(i<TOPE_SUBPROG){
                strcat(_pattern,ts_subprog[i].nombre);
                if(i<TOPE_SUBPROG-1){
                    strcat(_pattern,",");
                }
                i++;
            }
            strcat(_pattern,")");
            cWriteCode(_pattern);
        }
        TOPE_SUBPROG = 0;
        free(_pattern);
    }
    addChar(';');
    addChar('\n');
    decvariable=2;
}

// Comprueba si el tipoDatode la expresión coincide con lo que devuelve la función
void tsCheckReturn(atributos expr, atributos* res){

	int index = tsGetNextfuncion();
	//printf("\nFOUND_FUNCTION:%s\n",ts[index].nombre);
	//printTS();
	if (index > -1) {
		//printf("Ha encontrado una FUNCION en la pila\n");

		if (expr.tipoDato!= ts[index].tipoDato) {
            char* expT =  tipoAstring(expr.tipoDato);
            char* tipo = tipoAstring(ts[index].tipoDato);
			printf("Semantic Error(%d): Return of type %s does not equal return type %s of function %s.\n",
                    line,expT,tipo ,ts[index].nombre);
            free(expT);
            free(tipo);
			return;
		}

		res->tipoDato = expr.tipoDato;
		res->lista = expr.lista;
		res->es_constante = res->es_constante;

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

		res->nombre = ts[index].nombre;
		res->tipoDato= ts[index].tipoDato;
		res->lista = ts[index].lista;
		res->es_constante = ts[index].es_constante;

	}

}

// Realiza la comprobación de !, #, $.
void tsOpUnary(atributos op, atributos o, atributos* res){
	int index = tsSearchId(o);
    if(op.attr==0){
        // Not operator not available to lists.
        if(ts[index].lista || ts[index].tipoDato!=TIPOBOOL){
		    printf("Semantic Error(%d): Not operator expects logic expression.", line);
        }
        res->tipoDato= TIPOBOOL;
    }else{
        if(ts[index].lista){
            if(op.attr==1){
                res->tipoDato= ENTERO;
            }else{
		        printf("Semantic Error(%d): Expression not allowed in this context for lists.", line);
            }
         }else if(ts[index].tipoDato==COMPLEJO){
             res->tipoDato = REAL;
         }
     }
    res->lista = 0;
    res->es_constante = 1;
}

void tsCheckLeftList(atributos l, atributos a, atributos* res){

	int index = tsSearchId(l);
	//printf("\n%d\n",ts[index].lista);
    if(!sigsig){
        if(!ts[index].lista || a.tipoDato!=ENTERO){
            printf("Semantic Error(%d): El operador @ solo funciona con listas y enteros",line);
        }
        sigsig = 0;
    }

	res->tipoDato = ts[index].tipoDato;
	res->lista = 0;
	res->es_constante = 1;
}


// Realiza la comprobación de la operación +, -
void tsOpSign(atributos op, atributos o, atributos* res){

	if ((o.tipoDato!= REAL && o.tipoDato!= ENTERO) || isList(o)) {
		printf("Semantic Error(%d): El operador espera una expresión de tipo entero o real ", line);
	}

	res->tipoDato= o.tipoDato;
	res->lista = o.lista;
	res->es_constante = o.es_constante;

}

// Realiza la comprobación de la operación +, - binaria
void tsOpAdditivo(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

	if (isList(o1) && isList(o2)){

			res->tipoDato= o1.tipoDato;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;

	} else {

		if (isList(o1) && !isList(o2)) {
			res->tipoDato= o1.tipoDato;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;

		}

		if (!isList(o1) && isList(o2)){

			if (strcmp(op.nombre,"-")==0){

				printf("Semantic Error(%d): Operación no permitada.", line);
				return;

			} else {

				res->tipoDato= o2.tipoDato;
				res->lista = o2.lista;
				res->es_constante = o2.es_constante;

			}

		}

	}

}


// Realiza la comprobación de la operación ++, --
void tsOpSignSign(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

	if (!isList(o1) && o2.tipoDato != ENTERO){
		printf("Semantic Error(%d): Operación no permitida", line);
		return;

	}


}

void ErrorTipo(atributos o1, atributos o2){
	if (o1.tipoDato!= o2.tipoDato) {
        char* tipoA = tipoAstring(o1.tipoDato);
        char* tipoB = tipoAstring(o2.tipoDato);
		printf("Semantic Error(%d): Las expresión deben ser del mismo tipo. %s no es igual a %s",
							line, tipoA, tipoB);
        free(tipoA);
        free(tipoB);
	}
}

// Realiza la comprobación de la operación *, /, **, %
void tsOpMul(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) {
		printf("Semantic Error%d): La operación debe ser con enteros o reales.", line);
		return;
	}

    if(op.attr==11 && o1.tipoDato!=ENTERO && o2.tipoDato!=ENTERO){
		printf("Semantic Error%d): La operación debe ser con enteros.", line);
        return;
    }

	if (isList(o1) && isList(o2)){
			res->tipoDato= o1.tipoDato;
			res->lista = o1.lista;
			res->es_constante = o1.es_constante;
	} else {
		if (isList(o1) && !isList(o2)) {
			if(op.attr != 3){
				res->tipoDato= o1.tipoDato;
				res->lista = o1.lista;
				res->es_constante = o1.es_constante;
			}
			else{
				printf("Semantic Error(%d): Esa operación solo es válida con Listas\n",line);
			}

		}

		if (!isList(o1) && isList(o2)){
			if(op.attr != 3){
				res->tipoDato= o2.tipoDato;
				res->lista = o2.lista;
				res->es_constante = o2.es_constante;
			}
			else{
				printf("Semantic Error(%d): Esa operación solo es válida con Listas\n",line);
			}
		}
	}
}

// Realiza la comprobación de la operación &&
void tsOpAnd(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->lista = 0;
	res->es_constante = 0;

}

void tsOpXOr(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->lista = 0;
	res->es_constante = 0;

}

// Realiza la comprobación de la operación ||
void tsOpOr(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);
	if (o1.tipoDato!= TIPOBOOL || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects TIPOBOOL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->lista = 0;
	res->es_constante = 0;

}

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if (isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):El valor de una lista es ambiguo, no puede usar en un condicional.", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->lista = 0;
	res->es_constante = 0;


}

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(atributos o1, atributos op, atributos o2, atributos* res){

    ErrorTipo(o1,o2);

	if ((o1.tipoDato!= ENTERO && o1.tipoDato!= REAL) || isList(o1) || isList(o2)) {
		printf("Semantic Error(%d):Los valores deben ser los mismos. Expects ENTERO or REAL", line);
		return;
	}

	res->tipoDato= TIPOBOOL;
	res->lista = 0;
	res->es_constante = 0;

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
                        char* tipoA =  tipoAstring(ts[pos_limit].tipoDato);
                        char* tipoB =  tipoAstring(ts_subprog[TOPE_SUBPROG].tipoDato);
                        printf("Semantic Error(%d): El parámetro %s es de tipo %s pero se espera un tipo %s \n",
                                line ,ts[pos_limit].nombre,tipoA ,
                                tipoB);
                        free(tipoA);
                        free(tipoB);
                    }
                    pos_limit--;
                    TOPE_SUBPROG--;
                }
                currentFunction = index;
                //res->nombre = strealloc(nombre ,ts[index].nombre);
                res->tipoDato= ts[index].tipoDato;
								res->lista = ts[index].lista;
								res->es_constante = ts[index].es_constante;
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

}

//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Visualización
//

// Muestra una in de la tabla de símbolos
void printIn(int row){

	entradaTS e = ts[row];
	printf("\n\nTipo Entrada: %d\nLexema: %s\nTipo Dato: %d\nNum Parametros: %d\n",
		e.entrada, e.nombre, e.tipoDato, e.nParam);

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
		j++;
	}
	printf("--------------------------------\n");

    free(t);
    free(e);
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

    free(t);
    free(e);

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
	printf("-------------------------------\n");

    free(t);
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
int sigsig = 0;
int TS_ETIQ = 0;
etiquetas ts_etiq[50];

void addDesc(char* resultado){
    etiquetas etiq;
    etiq.etiqueta = NULL;
    etiq.etiqueta = strealloc( etiq.etiqueta ,resultado);
    ts_etiq[TS_ETIQ] = etiq;
    TS_ETIQ++;
}

void delDesc(){
    TS_ETIQ--;
}

void generaGOTO(char* etq){
    char* resultado;
    char* pattern = NULL;
    pattern = strealloc(pattern ,"goto %s ;\n");
    asprintf(&resultado,pattern,etq);
    cWriteCode(resultado);
    free(pattern);
    free(resultado);
}


char* generarEtiqueta(){
    char* resultado;
    asprintf(&resultado,"etiqueta_%d",num_etiqueta);
    addDesc(resultado);
	num_etiqueta++;

	return resultado;
}

char* generarVariableTemporal() {
    char* resultado;
    asprintf(&resultado,"tmp_%d",num_var);
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
	fputs("#include \"dec_complex.c\"\n",MAIN);
    fputs("\n",MAIN);
	fputs("#include <stdio.h>\n",FUNC);
	fputs("#include <stdbool.h>\n", FUNC);
	fputs("#include \"dec_data.c\"\n",FUNC);
	fputs("#include \"dec_complex.c\"\n",FUNC);
    fputs("#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))\n",FUNC);
    fputs("#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))\n",FUNC);
    fflush(MAIN);
    fflush(FUNC);
}

void cerrarArchivos(){
    fflush(MAIN);
    fflush(FUNC);
    fclose(MAIN);
    fclose(FUNC);
}

void cMarkOut(){
    cWriteCode("\n}\n");
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

    dtipo tipo = var.tipoDato;
    if ( tipo == ENTERO ) {
        strcpy(resultado,"int ");
	} else if ( tipo == REAL ) {
        strcpy(resultado,"float ");
	} else if ( tipo == TIPOBOOL ) {
        strcpy(resultado,"bool ");
	} else if ( tipo == CARACTER ) {
        strcpy(resultado,"char ");
	}else if (tipo == COMPLEJO ){
        strcpy(resultado,"struct complejo ");
    }else if (tipo== DESCONOCIDO){
        strcpy(resultado,"desconocido ");
    }


    if(var.lista){
        char* temp = NULL;
        temp = strealloc(temp ,resultado);
        strcpy(resultado,"struct listade");
        strcat(resultado,temp);
        free(temp);
    }
    cWriteCode(resultado);
    free(resultado);
}


void addChar(char c){
    char* out;
    asprintf(&out,"%c",c);
    cWriteCode(out);
    free(out);
}

char* getADD(int a){
    char* tmp = NULL;
    tmp = strealloc(tmp ,"+");
    if(a==1)
        tmp[0] = '-';
    return tmp;
}

void addADD(atributos a){
    char* add = getADD(a.attr);
    cWriteCode(add);
    free(add);
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

    char* tmp;
    if(index<0){
        char* var = generarVariableTemporal();
        asprintf(&tmp,"%s",var);
        free(var);
    }else
        asprintf(&tmp,"%s",ts[index].nombre);

    cWriteCode(tmp);
    free(tmp);
}

void cWriteName(atributos a){
    cWriteCode(a.nombre);
}

void cWriteCode(char* code){
    if(subProg>0 || decParam)
        fwrite(code,sizeof(char),strlen(code),FUNC);
    else
        fwrite(code,sizeof(char),strlen(code),MAIN);
}

void generaCodigoVariableTemporal(atributos a, atributos* res){
    tipoAtipoC(a);
    char* var = malloc(255);
    strcpy(var,res->nombre);
    strcat(var,";\n");
    cWriteCode(var);
    free(var);
}
void generaCodigoAsignacion(atributos a, atributos b){
    decvariable=1;
    cWriteIdent(a);
    addChar('=');
    cWriteName(b);
    addChar(';');
    addChar('\n');
    decvariable=2;
}

void generaCodigoLambda(atributos assign, atributos cond, atributos pos, atributos neg){
    char* _pattern = NULL;
    _pattern = strealloc(_pattern ,"if(!%s) goto %s;\n");
    char* _code;
    neg.etiq1 = generarEtiqueta(); // Etiqueta negativa;
    neg.etiq2 = generarEtiqueta();  // Etiqueta de salida;

    asprintf(&_code,_pattern, cond.nombre, neg.etiq1);
    cWriteCode(_code);
    generaCodigoAsignacion(assign,neg);
    _pattern = strealloc(_pattern ,"goto %s;\n");
    asprintf(&_code,_pattern,neg.etiq2);
    cWriteCode(_code);
    _pattern = strealloc(_pattern ,"%s:\n");
    asprintf(&_code,_pattern, neg.etiq1);
    cWriteCode(_code);
    generaCodigoAsignacion(assign,pos);
    _pattern = strealloc(_pattern ,"%s:\n");
    asprintf(&_code,_pattern, neg.etiq2);
    cWriteCode(_code);

    free(_pattern);
    free(_code);
}

void generaCodigoOpAditivo(atributos a, atributos op, atributos b, atributos* res){
    res->codigo;
    char* _code = NULL;
    if(op.attr==0){
        if(!a.lista && !b.lista)
            _code = strealloc(_code ,"%s = %s + %s;\n");
        if(a.lista && !b.lista)
            _code = strealloc(_code ,"%s = IntOperationLista%s(%s,%s,1);\n");
        if(!a.lista && b.lista)
            _code = strealloc(_code ,"%s = getIntFromlista%s(%s,%s,1);\n");
    }else{
        if(!a.lista && !b.lista)
            _code = strealloc(_code ,"%s = %s - %s;\n");
        if(a.lista && !b.lista)
            _code = strealloc(_code ,"%s = IntOperationLista%s(%s,%s,0);\n");
        if(!a.lista && b.lista)
            _code = strealloc(_code ,"%s = getIntFromlista%s(%s,%s,0);\n");
    }
    if(!a.lista && !b.lista)
        asprintf(&res->codigo,_code,res->nombre, a.nombre, b.nombre);
    else if(a.lista){
        char* tipoA = tipoAstring(a.tipoDato);
        asprintf(&res->codigo,_code,res->nombre,tipoA , a.nombre, b.nombre);
        free(tipoA);
    }else{
        int index = tsSearchId(b);
        char* tipoA = tipoAstring(ts[index].tipoDato);
        asprintf(&res->codigo,_code,res->nombre,tipoA,
                b.nombre, a.nombre);
        free(tipoA);
    }
    cWriteCode(res->codigo);
    free(_code);
    free(res->codigo);
}

void generaSigno(atributos op, atributos b, atributos* res){
    res->nombre;
    char* _code = NULL ;
    if(op.attr==0)
       _code = strealloc(_code ,"+%s");
    else
       _code = strealloc(_code ,"-%s");
    asprintf(&res->nombre,_code,b.nombre);
    free(_code);
}

void generaCodigoOpMultiplicativo(atributos a, atributos op, atributos b, atributos* res){
    res->codigo;
    char* _code = NULL ;
    if(op.attr==0){
        if(!a.lista && !b.lista)
            _code = strealloc(_code ,"%s = %s * %s;\n");
        if(a.lista && !b.lista)
            _code = strealloc(_code ,"%s = IntOperationLista%s(%s,%s,2);\n");
        if(!a.lista && b.lista)
            _code = strealloc(_code ,"%s = getIntFromlista%s(%s,%s,2);\n");
    }else if(op.attr==1){
        if(!a.lista && !b.lista)
            _code = strealloc(_code ,"%s = %s / %s;\n");
        if(a.lista && !b.lista)
            _code = strealloc(_code ,"%s = IntOperationLista%s(%s,%s,3);\n");
        if(!a.lista && b.lista)
            _code = strealloc(_code ,"%s = getIntFromlista%s(%s,%s,3);\n");
    }else if(op.attr==11){
        _code = strealloc(_code ,"%s = %s / %s;\n");
    }
    else if(op.attr==2){
        if(!a.lista)
            _code = strealloc(_code ,"%s = %s %% %s;\n");
        else
            _code = strealloc(_code ,"%s = borrarLista%s(%s,%s);\n");
    }else if(op.attr==3)
       _code = strealloc(_code ,"%s = concatenerListas(%s,%s);\n");

    if((!a.lista && !b.lista) || op.attr==3)
        asprintf(&res->codigo,_code,res->nombre, a.nombre, b.nombre);
    else if(a.lista){
        char* tipoA = tipoAstring(a.tipoDato);
        asprintf(&res->codigo,_code,res->nombre,tipoA,
                a.nombre, b.nombre);
        free(tipoA);
    }else{
        int index = tsSearchId(b);
        char* tipoA = tipoAstring(ts[index].tipoDato);
        asprintf(&res->codigo,_code,res->nombre,tipoA,
                b.nombre, a.nombre);
        free(tipoA);
    }
    cWriteCode(res->codigo);
    free(_code);
    free(res->codigo);
}

void generaCodigoOpRelacion(atributos a, atributos op, atributos b, atributos* res){
    res->codigo;
    char* _code = NULL;
    if(op.attr==0)
       _code = strealloc(_code ,"%s = %s < %s;\n");
    else if(op.attr==1)
       _code = strealloc(_code ,"%s = %s > %s;\n");
    else if(op.attr==2)
       _code = strealloc(_code ,"%s = %s <= %s;\n");
    else if(op.attr==3)
       _code = strealloc(_code ,"%s = %s >= %s;\n");
    asprintf(&res->codigo,_code,res->nombre, a.nombre, b.nombre);
    cWriteCode(res->codigo);
    free(_code);
    free(res->codigo);
}

void generaCodigoReturn(atributos a){
    a.codigo;
    asprintf(&a.codigo,"return %s;\n",a.nombre);
    cWriteCode(a.codigo);
    free(a.codigo);
}

void generaCodigo(char* pattern, char* a, char* b, char* c){
    char* resultado;
    asprintf(&resultado,pattern,a,b,c);
    cWriteCode(resultado);
    free(resultado);
}

void generaCodigoUnario(atributos op, atributos a, atributos* res){
    res->codigo;
    char* _code = NULL ;
    if(op.attr==0)
       _code = strealloc(_code ,"%s = !%s;\n");
    else if(op.attr==1){
        if(a.lista)
            _code = strealloc(_code ,"%s = getLongitudLista%s(%s);\n");
        if(a.tipoDato==COMPLEJO){
            _code = strealloc(_code ,"%s = getReal(%s);\n");
        }
    }if(op.attr==2)
        _code = strealloc(_code ,"%s = getImaginaria(%s);\n");
    else if(op.attr==3)
       _code = strealloc(_code ,"%s = getActualLista%s(%s);\n");


    if(a.tipoDato==COMPLEJO){
        asprintf(&res->codigo,_code,res->nombre, a.nombre);
    }else{
        char* tipoA = tipoAstring(a.tipoDato);
        asprintf(&res->codigo,_code,res->nombre, tipoA,a.nombre);
        free(tipoA);
    }
    cWriteCode(res->codigo);
    free(res->codigo);
    free(_code);
}

void generaCodigoSi(atributos* a, atributos exp){
    char* _code = NULL;
    char* pattern = NULL;
    pattern = strealloc(pattern ,"if(!%s) goto %s;\n");
    a->etiq1 = generarEtiqueta();
    asprintf(&_code,pattern,exp.nombre,a->etiq1);
    cWriteCode(_code);
    free(_code);
    free(pattern);
}


char* tipoAprintf(dtipo tipo) {
    char* resultado = NULL;
	if ( tipo == ENTERO ) {
		resultado = strealloc(resultado , "%d");
	} else if ( tipo == REAL ) {
		resultado = strealloc(resultado , "%f");
	} else if ( tipo == TIPOBOOL ) {
		resultado = strealloc(resultado , "%d");
	} else if ( tipo == CARACTER ) {
		resultado = strealloc(resultado , "%c");
	} else if ( tipo == TIPOCADENA ) {
		resultado = strealloc(resultado , "%s");
    }

	return resultado;
}

void generarE_S(char* E_S, int tipo){
    int i = 0;
    char* res = malloc(255); ;
    snprintf(res,255,"%s",E_S);
    while(i<TOPE_SUBPROG){
        strcat(res,tipoAprintf(ts_subprog[i].tipoDato));
        i++;
    }
    i=0;
    strcat(res,"\",");
    while(i<TOPE_SUBPROG){
        if(tipo==0)
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


char* generarFuncion(char* nombre){
    int i = 0;
    char* res = malloc(255); ;
    snprintf(res,255,"%s",nombre);
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
    snprintf(etq,255,"%s",etiq1);
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
    char* resultado;
    char* pattern = NULL;
    pattern = strealloc(pattern ,"%s = %s");
    char* var = generarFuncion(in.nombre);
    asprintf(&resultado,pattern,res->nombre,var);
    cWriteCode(resultado);
    free(resultado);
    free(pattern);
    free(var);
}

void moverCursor(atributos a,atributos op){
    char* pattern = NULL;
    if(op.attr==0){
    pattern = strealloc(pattern ,"retrocederLista%s(&%s);\n");
    }else if(op.attr==1){
    pattern = strealloc(pattern ,"avanzarLista%s(&%s);\n");
    }else{
    pattern = strealloc(pattern ,"irAPosicion%s(&%s,0);\n");
    }
    int index = tsSearchId(a);
    char* code;
    char* tipoA = tipoAstring(ts[index].tipoDato);
    asprintf(&code,pattern,tipoA,a.nombre);
    free(tipoA);
    cWriteCode(code);
    free(pattern);
    free(code);
}

void generaCreacionLista(atributos a){
    int i = 0;
    char* res;
    i=TOPE_SUBPROG-1;
    char* var_name;
    char* tipo = tipoAstring(a.tipoDato);
    asprintf(&var_name, "listade%s",tipo);
    asprintf(&res,"struct %s %s= %s_default;\n",var_name,a.nombre,var_name);
    cWriteCode(res);
    free(res);
    free(var_name);
    var_name = NULL;
    var_name = strealloc(var_name ,a.nombre);
    char* pattern = strealloc(pattern ,"insertar%s(&%s,%s);\n");
    while(i>=0){
        asprintf(&res,pattern,tipo,var_name,ts_subprog[i].nombre);
        cWriteCode(res);
        free(res);
        i--;
    }
    TOPE_SUBPROG = 0;
    free(var_name);
    free(pattern);
    free(res);
    free(tipo);
}

void freeEverything(atributos *res){
    if(res->nombre!=NULL)
        free(res->nombre);
    if(res->codigo!=NULL)
        free(res->codigo);
    if(res->etiq1!=NULL)
        free(res->etiq1);
    if(res->etiq2!=NULL)
        free(res->etiq2);
}

void freeTable(){

    unsigned int i = 0;
    for(i=0;i<MAX_IN;i++){
        if(ts[i].nombre!=NULL){
            free(ts[i].nombre);
        }
	}

    for(i=0;i<MAX_SUBPROG;i++){
        if(ts_subprog[i].nombre!=NULL){
            freeEverything(&ts_subprog[i]);
        }
    }
}

void *strealloc(char *origptr, char *strdata)
{
    size_t nbytes = strlen(strdata) + 1;
    char *newptr = (char *) realloc(origptr, nbytes); /* cast needed for C++ */
    if (newptr)
      memcpy(newptr, strdata, nbytes);
    return newptr;
}
