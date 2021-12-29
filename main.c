#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <stdbool.h>
#include <windows.h>
#define cant 40

int main()
{
    SetConsoleTitle("REGUISTRO");
    persona datos[cant];
    iniciar(datos);


    saludo();

    bool repite = true;
    int opcion;

    // Título y las opciones del menú
    char *titulo="*****MENU PRINCIPAL*****";
    char *opciones[]= {"INGRESAR DATOS POR PANTALLA","BUSQUEDA DE DATO","BAJA DE DATOS"
                       ,"MOSTRAR TODOS LOS DATOS","MOSTRAR ACTIVOS","LISTADO ORDENADO A a Z","PORCENTAJE GRAFICO","SALIR DEL PROGRAMA "
                      };
    int n = 8; // Número de opciones
    do
    {

        opcion = menu(titulo, opciones, n);

        switch(opcion)
        {

        case 1:
            alta(datos);
            break;
        case 2:
            busqueda(datos);
            break;
        case 3:
            baja(datos);
            break;
        case 4:
            mostrar(datos);
            break;
        case 5:
            mostrarDatos(datos);
            break;
        case 6:
            mostrar_orden(datos);
            break;
        case 7:
            mostrarGrafico(datos);
            break;
        case 8:
            repite=false;
            system("cls");
            system ("color 3");
            gotoxy(1,8);
            Sleep(150);
            printf(" #######   ####    ##   ##           #####    #######           ######   ######   ##   ##  #######  ######     ##");
            gotoxy(1,9);
            Sleep(150);
            printf("  ##   #    ##     ###  ##            ## ##    ##   #            ##  ##   ##  ##  ##   ##   ##   #   ##  ##   ####");
            gotoxy(1,10);
            Sleep(150);
            printf("  ## #      ##     #### ##            ##  ##   ## #              ##  ##   ##  ##  ##   ##   ## #     ##  ##  ##  ##");
            gotoxy(1,11);
            Sleep(150);
            printf("  ####      ##     ## ####            ##  ##   ####              #####    #####   ##   ##   ####     #####   ##  ##");
            gotoxy(1,12);
            Sleep(150);
            printf("  ## #      ##     ##  ###            ##  ##   ## #              ##       ## ##   ##   ##   ## #     ##  ##  ######");
            gotoxy(1,13);
            Sleep(150);
            printf("  ##        ##     ##   ##            ## ##    ##   #            ##       ##  ##  ##   ##   ##   #   ##  ##  ##  ##");
            gotoxy(1,14);
            Sleep(150);
            printf(" ####      ####    ##   ##           #####    #######           ####     #### ##   #####   #######  ######   ##  ##");
            break;
        }

    }
    while(repite);



    return 0;
}
