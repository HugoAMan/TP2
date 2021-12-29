#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#define TECLA_ARRIBA 72
#define TECLA_ABAJO 80
#define ENTER 13

#define ESC  27

//Caracteres escenario:
#define ESQ_SI	201
#define ESQ_SD	187
#define ESQ_II	200
#define ESQ_ID	188
#define BAR_H	205
#define BAR_V	186

//Dimensiones escenario:
#define NX	40
#define NY	20
#define XBOUND	1
#define YBOUND	1

//Dimensiones escenario2:
#define NXX	70
#define NYY	25
#define XXBOUND 45
#define YYBOUND	3
#define cant 40

typedef struct persona
{

    char nombre[cant];
    int dni;
    int edad;
    int status;

} persona;

void saludo();
void iniciar(persona persona[cant]);


void gotoxy(int x,int y);
int menu(char *titulo, char *opciones[], int n);
void alta(persona persona[cant]);
void baja(persona persona[cant]);
int buscar(persona persona[cant]);
void busqueda(persona persona[cant]);
void mostrar(persona persona[cant]);
void mostrar_orden(persona persona[cant]);
void mostrarGrafico(persona persona[cant]);

#endif // FUNCIONES_H_INCLUDED
