#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>
#include "funciones.h"

#define VACIO 0
#define ACTIVO 1
#define BORRADO 2

#define cant 40
#define MAX 10

#define FIL 20
#define COL 3


void iniciar(persona persona[cant])
{

    for(int i = 0 ; i < MAX ; i ++ )
    {

        strcpy(persona[i].nombre,"sin data");
        persona[i].dni = 0;
        persona[i].edad = 0;

        persona[i].status = VACIO;
    }

}



void alta(persona persona[cant])
{
    int n;
    char numero[33];
    gotoxy(50,4);
    printf("LLene los datos: ");

    for(int i = 0 ; i < MAX ; i++)
    {

        if(persona[i].status == VACIO)
        {

            fflush(stdin);
            gotoxy(46,6);
            printf("Nombre y Apellido: ");
            gets(persona[i].nombre);

            gotoxy(46,7);
            printf("D.N.I: ");
            scanf("%d",&persona[i].dni);


            gotoxy(46,8);
            printf("Edad: ");
            scanf("%d",&persona[i].edad);

            persona[i].status = ACTIVO;

            system("cls");
            break;

        }
    }

}

void baja(persona persona[cant])
{

    gotoxy(50,4);
    printf("Baja de datos: \n");

    int posicion = buscar(persona);

    if(posicion != -1)
    {

        persona[posicion].status = BORRADO;

    }
    else
    {
        system("color 4");
        gotoxy(65,15);
        char no[33]="PERSONA NO ENCONTRADA" ;
        for(int i=0; i<33; i++)
        {
            printf("%c",no[i]);
            Sleep(50);

        }
    }
    Sleep(500);
}
int buscar(persona persona[cant])
{

    int pos = -1;
    int dNi;

    gotoxy(46,4);
    printf("Por favor ingrese el D.N.I: ");
    scanf("%d", &dNi);

    for(int i = 0 ; i < MAX ; i++)
    {

        if(persona[i].status == ACTIVO && persona[i].dni == dNi)
        {
            pos = i;
            break;
        }
    }

    return pos;

}

void busqueda(persona persona[cant])
{

    int posicion;

    gotoxy(50,4);
    printf("Busqueda de datos: \n");

    posicion = buscar(persona);

    if(posicion != -1)
    {

        gotoxy(46,6);
        printf(
            "Nombre y Apellido: %s "
            "    D.N.I: %d "
            "    Edad: %d",
            persona[posicion].nombre,
            persona[posicion].dni,
            persona[posicion].edad
        );
        gotoxy(46,28);
        system("pause");


        }
   else {
        system("color 4");
        gotoxy(65,15);
        char no[33]="PERSONA NO ENCONTRADA" ;
        for(int i=0; i<33; i++)
        {
            printf("%c",no[i]);
            Sleep(50);
        }
        Sleep(500);
    }

}


void mostrarGrafico(persona persona[cant])
{



    char matriz[FIL][COL];

    for(int i = 0; i < 10 ; i++)  // Se ponen los * en la matriz
    {

        if(persona[i].status == ACTIVO)
        {

            if(persona[i].edad <= 18)
            {
                matriz[i][1] = '#';
            }
            if(persona[i].edad >= 19 && persona[i].edad <= 35)
            {
                matriz[i][2] = '#';
            }
            if(persona[i].edad > 35)
            {
                matriz[i][3] = '#';
            }

        }

    }

    //Se muestra el recuadro

    for(int i = 0 ; i < 10 ; i++)
    {
        if(persona[i].status == ACTIVO)
        {
            gotoxy(46,i+5);
            printf("%s (%d)\n",persona[i].nombre,persona[i].edad);
        }
    }

    gotoxy(70,4);
    printf("-18");
    gotoxy(80,4);
    printf("19 - 35");
    gotoxy(90,4);
    printf("+35");

    for(int i = 0; i < 10 ; i++)
    {

        if(persona[i].status == ACTIVO)
        {
            if(persona[i].edad <= 18)
            {
                gotoxy(70,i+5);
                printf("%c",matriz[i][1]);
            }

            printf("\n\n");

            if(persona[i].edad >= 19 && persona[i].edad <= 35)
            {
                gotoxy(80,i+5);
                printf("%c",matriz[i][2]);
            }

            printf("\n\n");

            if(persona[i].edad > 35)
            {
                gotoxy(90,i+5);
                printf("%c",matriz[i][3]);
            }
        }
    }

    printf("\n\n");
    gotoxy(46,28);
    system("pause");
    system("cls");
}
//FUNCIONES DE IMPRESIÓN:
void gotoxy(int x, int y)
{
    printf("%c[%d;%dH", ESC, y, x);
}
int menu(char *titulo, char *opciones[], int n)
{

    int opcionSeleccionada = 1;
    int tecla;
    bool repite = true;

    do
    {
        system("cls");

        system("color 17");
        int i, j;
        char c;
        gotoxy(XBOUND, YBOUND);
        for(j=0; j<NY+2; ++j)
        {
            for(i=0; i<NX+2; ++i)
            {
                //Columnas:
                if(i==0 || i==NX+1)
                {
                    switch(j)
                    {
                    case 0:
                        c = ESQ_SI*(i==0) + ESQ_SD*(i==NX+1);
                        break;
                    case NY+1:
                        c = ESQ_II*(i==0) + ESQ_ID*(i==NX+1);
                        break;
                    default:
                        c = BAR_V;
                        break;
                    }
                }
                //Entre medias:
                else
                {
                    if(j==0 || j==NY+1)
                    {
                        c = BAR_H;
                    }
                    else
                    {
                        c = ' ';
                    }
                }
                printf("%c",c);
                if(i==NX+1)
                {
                    gotoxy(XBOUND, YBOUND+j+1);
                }
            }
        }
        int A, B;
        char D;
        gotoxy(XXBOUND, YYBOUND);
        for(B=0; B<NYY+2; ++B)
        {
            for(A=0; A<NXX+2; ++A)
            {
                //Columnas:
                if(A==0 || A==NXX+1)
                {
                    switch(B)
                    {
                    case 0:
                        D = ESQ_SI*(A==0) + ESQ_SD*(A==NXX+1);
                        break;
                    case NYY+1:
                        D = ESQ_II*(A==0) + ESQ_ID*(A==NXX+1);
                        break;
                    default:
                        D = BAR_V;
                        break;
                    }
                }
                //Entre medias:
                else
                {
                    if(B==0 || B==NYY+1)
                    {
                        D = BAR_H;
                    }
                    else
                    {
                        D = ' ';
                    }
                }
                printf("%c",D);
                if(A==NXX+1)
                {
                    gotoxy(XXBOUND, YYBOUND+B+1);
                }
            }
        }

        gotoxy(1,30);
        printf("Utilice 'FLECHA ARRIBA' o'FLECHA ABAJO' para desplazarse ");
        gotoxy(1,29);
        printf("ENTER para seleccionar");
        gotoxy(3, 1+ opcionSeleccionada);
        printf("==>");


        gotoxy(50,1);
        printf("%s",titulo);
        // Imprime las opciones
        for (int i = 0; i < n; i++)
        {
            gotoxy(6, 2 + i);
            printf(" %s",opciones[i]);
        }

        do
        {

            tecla = getch();
        }
        while (tecla != TECLA_ARRIBA && tecla != TECLA_ABAJO && tecla != ENTER);

        switch (tecla)
        {
        case TECLA_ARRIBA:
            opcionSeleccionada--;

            if (opcionSeleccionada < 1)
            {
                opcionSeleccionada = n;
            }
            break;

        case TECLA_ABAJO:
            opcionSeleccionada++;

            if (opcionSeleccionada > n)
            {
                opcionSeleccionada = 1;
            }
            break;

        case ENTER:
            repite = false;
            break;
        }

    }
    while (repite);


    return opcionSeleccionada;
}
void saludo()
{

    system ("color 3");
    Sleep(150);
    gotoxy(5,8);
    printf(":::::::::  ::::::::::: :::::::::: ::::    ::: :::     ::: :::::::::: ::::    ::: ::::::::::: :::::::::   :::::::: ");
    Sleep(150);
    gotoxy(5,9);
    printf(":+:    :+:     :+:     :+:        :+:+:   :+: :+:     :+: :+:        :+:+:   :+:     :+:     :+:    :+: :+:    :+:");
    Sleep(150);
    gotoxy(5,10);
    printf("+:+    +:+     +:+     +:+        :+:+:+  +:+ +:+     +:+ +:+        :+:+:+  +:+     +:+     +:+    +:+ +:+    +:+");
    Sleep(150);
    gotoxy(5,11);
    printf("+#++:++#+      +#+     +#++:++#   +#+ +:+ +#+ +#+     +:+ +#++:++#   +#+ +:+ +#+     +#+     +#+    +:+ +#+    +:+");
    Sleep(150);
    gotoxy(5,12);
    printf("+#+    +#+     +#+     +#+        +#+  +#+#+#  +#+   +#+  +#+        +#+  +#+#+#     +#+     +#+    +#+ +#+    +#+");
    Sleep(150);
    gotoxy(5,13);
    printf("#+#    #+#     #+#     #+#        #+#   #+#+#   #+#+#+#   #+#        #+#   #+#+#     #+#     #+#    #+# #+#    #+#");
    Sleep(150);
    gotoxy(5,14);
    printf("#########  ########### ########## ###    ####     ###     ########## ###    #### ########### #########   ######## ");

    system("color 6");
    gotoxy(45,19);
    char saludo[33]=" al tp 2 de:" ;
    for(int i=0; i<33; i++)
    {
        printf("%c",saludo[i]);
        Sleep(50);
    }


    Sleep(150);
    gotoxy(35,23);
    printf("--------------------------------------------------");
    Sleep(150);
    gotoxy(35,24);
    printf("|*|        #lezcano franco.                     |*|");
    Sleep(150);
    gotoxy(35,25);
    printf("|*|        #yasinowsky alexis.                  |*|");
    Sleep(150);
    gotoxy(35,26);
    printf("|*|        #Manrique Hugo.                      |*|");
    Sleep(150);
    gotoxy(35,27);
    printf("|*|        #Rios Fernando.                      |*|");
    Sleep(150);
    gotoxy(35,28);
    printf("--------------------------------------------------");

    Sleep(2500);
    system("cls");
}
void mostrar(persona persona[cant])
{

    gotoxy(50,4);
    printf("Listado\n");
    for(int i = 0 ; i < MAX ; i++)
    {
        gotoxy(46,6+i);
        printf("Nombre y Apellido: %s"
               "     D.N.I: %d"
               "     Edad: %d",
               persona[i].nombre,
               persona[i].dni,
               persona[i].edad
              );
    }
    gotoxy(46,28);
    system("pause");
}
void mostrar_orden(persona persona[cant])  //----------------------------------Lista Ordenada de nombres
{



    int contador = 0;

    for(int i = 0 ; i < MAX ; i++)
    {

        if(persona[i].status == ACTIVO)
        {
            contador++; // contador para despues ponerlo en el for y que itere tantas veces como activos haya
        }

    }

    for(int i = 0 ; i < contador ; i++)
    {

        int estaOrdenado = 0;

        if(persona[i].status == ACTIVO)
        {

            for(int j = 0 ; j < contador - 1 ; j++)
            {

                if(strcmp(persona[j].nombre,persona[j+1].nombre) >=0)
                {

                    char aux [cant] ;

                    strcpy(aux,persona[j].nombre);
                    strcpy(persona[j].nombre,persona[j+1].nombre);
                    strcpy(persona[j+1].nombre,aux);
                    estaOrdenado = 1;
                }

            }
            if(estaOrdenado == 0)
            {
                break;
            }

        }
    }

    gotoxy(55,4);
    printf("LISTA ORDENADA DE NOMBRES\n\n");

    for(int i = 0 ; i < MAX ; i++)
    {

        gotoxy(46,6+i);
        printf("%s",persona[i].nombre);

    }

    gotoxy(46,28);
    system("pause");
    system("cls");
}

void mostrarDatos(persona persona[cant])  //---------------------------------- Muestra todos los datos
{



    gotoxy(55,4);
    printf("Mostrar todos los datos: \n");

    for(int i = 0 ; i < MAX ; i++)
    {

        if(persona[i].status == ACTIVO)
        {

            gotoxy(46,i+5);
            printf("Nombre y Apellido: %s"
                   "   D.N.I: %d"
                   "   Edad: %d",
                   persona[i].nombre,
                   persona[i].dni,
                   persona[i].edad
                  );

            // printf("\n\n");

        }

    }

    gotoxy(46,28);
    system("pause");
    system("cls");
}
