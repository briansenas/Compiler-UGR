#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum {
	MARCA = 0,//MARK = 0,
	FUNCION,//FUNCTION,
	VARIABLE,//VAR,
	PARAMETRO_FORMAL,//FORM

} tipoEntrada;

typedef enum {
	ENTERO=0,//NOT_ASIG = 0,
	REAL,//ENTERO,
	CARACTER,//CARACTER,
	TIPOBOOL,//BOOLEANO,
	TIPOLISTA,
    TIPOCADENA,
	DESCONOCIDO,
    NA

} dtipo;

typedef struct {

	tipoEntrada entrada;//in;
	char *nombre;//*lex;
	dtipo tipoDato;//type;
	int lista;
	int es_constante;
	unsigned int nParam;
	unsigned int nDim;

	// Tamaño de la dimensión 1
	int tamDimen1;//tDim1;

	// Tamaño de la dimensión 2
	int tamDimen2;//tDim2;


} entradaTS;

typedef struct {

	int attr;
	char *nombre;
    char *codigo;
    char* etiq1;
    char* etiq2;
	dtipo tipoDato;
	int lista;		// indica si es una lista
	int es_constante;		// indica si es constante
	unsigned int nDim;
	// Tamaño de la dimensión 1
	int tamDimen1;
    // Tamaño de la dimensión 2
	int tamDimen2;

} atributos;

#define YYSTYPE atributos

#define MAX_IN 500
#define MAX_SUBPROG 50					// número máximo de parámetros en un subprograma

extern unsigned long int TOPE;//LIMIT;

// Indica si se esta comprobando un subprograma
extern int callSub;

// Declaración de una segunda pila de atributos auxiliar para realizar las comprobaciones de los parámetros de un subprograma
extern entradaTS ts[MAX_IN];
extern unsigned long int TOPE_SUBPROG;
extern atributos ts_subprog[MAX_SUBPROG];
extern char* tipoAstring(dtipo tipo);
extern void tsCheckLeftList(atributos l, atributos o, atributos* ref);
extern int tsCheckList(atributos l);

// Línea del fichero que se está analizando
extern int line;

// Se indica si se están utilizando las variables (0) o si se están declarando
// (1), (2) llamada desde expresión
extern int decvariable;

// Indica el comienzo de un subprograma o función con 0 si es un bloque y 1 si
// es la cabecera del subprograma
extern int subProg;

// Indica si se están declarando parámetros formales en una función
extern int decParam;

//extern int decFunction;

// Variable global que almacena el tipo en las declaraciones
extern dtipo globaltipoDato;
extern int globalLista;

// Cuenta el número de parámetros de una función
extern int nParam;

// Índice de la tabla de símbolos de la función que se está utilizando
extern int currentFunction;
extern int aux;

// Devuelve si el atributo es array o no
int isList(atributos e);

// Devuelve si los dos posibles arrays que recibe tienen el mismo tamaño
int equalSize(atributos e1, atributos e2);

// Guarda el tipo de la variable
int setType(atributos value);

///////////////////////////////////////////////////////////////////////////////
// Tabla de Símbolos
//

// Inserta una entrada en la tabla de símbolos
int tsAddIn(entradaTS in);

// Elimina una entrada de la tabla de símbolos
int tsDelIn();

// Elimina las entradas de la tabla de símbolos hasta la marca de tope
void tsCleanIn();

// Busca una entrada según el identificador
int tsSearchId(atributos e);

// Busca una entrada según el nombre
int tsSearchName(atributos e);

// Añade un identificador
void tsAddId(atributos e);

// Añade una marca de tope
void tsAddMark();

// Añade una entrada de subprograma
void tsAddSubprog(atributos e);

// Añade una entrada de parametro formal
void tsAddParam(atributos e);

// Actualiza el número de parámetros de la función
void tsUpdateNparam(atributos e);

//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// Analizador Semántico
//

// Devuelve la entrada que sea función más cercana
int tsGetNextFunction();

// Comprueba si el tipo de la expresión coincide con lo que devuelve la función
void tsCheckReturn(atributos expr, atributos* res);

// Devuelve el identificar
void tsGetId(atributos id, atributos* res);

// Realiza la comprobación de la operación !, &, ~
void tsOpUnary(atributos op, atributos o, atributos* res);

// Realiza la comprobación de la operación +, -
void tsOpSign(atributos op, atributos o, atributos* res);

// Realiza la comprobación de la operación sigsig
void tsOpSignSign(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación additivo
void tsOpAdditivo(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación *, /
void tsOpMul(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación &&
void tsOpAnd(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación ||
void tsOpOr(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación XOR
void tsOpXOr(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación ==, !=
void tsOpEqual(atributos o1, atributos op, atributos o2, atributos* res);

// Realiza la comprobación de la operación <, >, <=, >=, <>
void tsOpRel(atributos o1, atributos op, atributos o2, atributos* res);

// Inserta los parámetros de la llamada a función
void TS_subprog_params(atributos atrib);

// Realiza la comprobación de la llamada a una función
void tsFunctionCall(atributos id, atributos* res);

// Realiza la comprobación de cada parámetro de una función
void tsCheckParam(atributos param, int checkParam);

//
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Visualización
//

// Muestra una entrada de la tabla de símbolos
void printIn(int row);

// Muestra el tipo de la entrada
void printInType(tipoEntrada tipo);

// Muestra el tipo del dato recibido
void printDataType(dtipo type);

// Muestra la tabla de símbolos
void printTS();
void printSPTS();

// Muestra un atributo recibido
void printAttr(atributos e, char *t);



extern int variable_main;
extern int num_etiqueta;
extern int num_var;
extern int Many;
extern int principal;
extern FILE* MAIN;
extern int asignar;
extern int isIf;
extern int cond;
typedef struct{
	char *etiqueta;
} etiquetas ;
extern etiquetas ts_etiq[50];
extern int TS_ETIQ;


int tsSearchParam(atributos a);
char* generarEtiqueta();
char* generarVariableTemporal();
void abrirArchivos();
void cerrarArchivos();
void cMarkIn();
void cMarkOut();
void tipoAtipoC();
void cSubProgParams();
void addNewLine();
void addPYC();
void addCOMMA();
void addPAR_A();
void addPAR_C();
void addASSIGN();
void generaGOTO(char* etq);
void addDesc(char* resultado);
void delDesc();
char* getADD(int a);
void writeLastGotos();
void addADD(atributos a);
void cWriteIdent();
void cWriteName();
void cWriteCode(char* code);
void generaCodigoVariableTemporal(atributos a, atributos* res);
void generaCodigoAsignacion(atributos a, atributos b);
void generaCodigoOpAditivo(atributos a, atributos op, atributos b, atributos* res);
void generaSigno(atributos op, atributos b, atributos* res);
void generaCodigoOpMultiplicativo(atributos a, atributos op, atributos b, atributos* res);
void generaCodigoOpRelacion(atributos a, atributos op, atributos b, atributos* res);
void generaCodigoReturn(atributos a);
void generaCodigo(char* pattern, char* a, char* b, char* c);
void generaCodigoUnario(atributos op, atributos a, atributos* res);
void generaCodigoSi(atributos* a, atributos exp);
void generaCodigoSiNo(atributos* a, atributos exp);
void generarE_S(char* E_S);
