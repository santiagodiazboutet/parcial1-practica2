#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define TAMPROG 50
#define TAMPROY 1000
int main()
{
    eProgramador listaProgramadores[TAMPROG];
    eProg_init(listaProgramadores,TAMPROG);
    eCategoria categorias[3];
    eCat_init(categorias);
    int aux=0;
    int opcion=0;
    while(opcion!=9)
    {
        printf("\n    MENU\n1-ALTA DE PROGRAMADOR\n2-MODIFICAR PROGRAMADO\n3-BAJA PROGRAMADOR");
        fflush(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            system("cls");
            aux=eProgramador_alta(listaProgramadores,TAMPROG);
            if(aux==-2)
            {
                printf("No hay lugar libre para realizar esta operacion, por favor contacte a su administrador de sistemas.");
            }
            system("cls");
            break;
        case 2:
            eProg_modificacion(listaProgramadores,TAMPROG,categorias);
             break;
        case 5:system("cls");
            printf("Listado de programadores");
            eProg_mostrarListado(listaProgramadores,TAMPROG,categorias);
            break;
        case 9:
            break;
        }
    }

}
