#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"
#define TAMPROG 50
#define TAMPROY 1000
#define OCUPADO 0
#define LIBRE 1



int eProg_init( eProgramador listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].id= 0;
        }
    }
    return retorno;
}

int eProgramador_buscarLugarLibre(eProgramador listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProgramador_siguienteId(eProgramador listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                    if(listado[i].id>retorno)
                    {
                         retorno=listado[i].id;
                    }

            }
        }
    }

    return retorno+1;
}
int eProgramador_alta(eProgramador  listado[],int limite)
{
    int retorno = -1;
    char nombre[50];
    char apellido[10];
    int id;
    int indice;
    int idCat=0;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eProgramador_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eProgramador_siguienteId(listado,limite);
            retorno = 0;
                    system("cls");
                    printf("\nIngrese el nombre del programador.\n");
                    fflush(stdin);
                    gets(nombre);
                    printf("\nIngrese el apellido.\n");
                    fflush(stdin);
                    gets(apellido);
                    strcpy(listado[indice].nombre, nombre);
                    strcpy(listado[indice].apellido, apellido);
                    listado[indice].id = id;
                    while(idCat<1||idCat>3)
                    {
                         printf("\nEliga la categoria del programador:\n1-Junior\n2-Semi-Senior\n3-Senior\n");
                         scanf("%d",&idCat);
                         if(idCat<1||idCat>3)
                         {
                             printf("Por favor ingrese un numero entre 1 y 3");
                         }
                    }
                    listado[indice].idCategoria=idCat;
                    listado[indice].estado = OCUPADO;

        }
    }
    return retorno;
}
void eCat_init(eCategoria categoria[])
{
    strcpy(categoria[0].descripcion,"Programador Junior");
    strcpy(categoria[1].descripcion,"Programador SemiSenior");
    strcpy(categoria[2].descripcion,"Programador Senior");
    categoria[0].idCategoria=001;
    categoria[1].idCategoria=002;
    categoria[2].idCategoria=003;
    categoria[0].sueldoHora=100;
    categoria[1].sueldoHora=200;
    categoria[2].sueldoHora=300;
}

void eProg_mostrarUno(eProgramador parametro)
{
     printf("\n %s %s -id: %d ",parametro.nombre,parametro.apellido,parametro.id);

}
void eCat_mostrarUno(eCategoria parametro)
{
     printf("-Puesto: %s",parametro.descripcion);

}

int eProg_mostrarListado(eProgramador listado[],int limite,eCategoria categoria[])
{
    int retorno = -1;
    int i;
    int j;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {
                j=eCat_buscarPorId(categoria,3,listado[i].idCategoria);
                eProg_mostrarUno(listado[i]);
                eCat_mostrarUno(categoria[j]);

            }
        }
    }
    return retorno;
}

int eCat_buscarPorId(eCategoria listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].idCategoria == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eProg_buscarPorId(eProgramador listado[] ,int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].id == id)
            {
                retorno = i;

                break;
            }
        }
    }
    return retorno;
}

int eProg_modificacion(eProgramador listado[] ,int limite, eCategoria categoria[])
{   int id;
    int i;
    int j;
    int opcion=0;
    while(opcion!=1&&opcion!=2&&opcion!=3)
    {
        eProg_mostrarListado(listado,limite,categoria);
        printf("\nIngrese id del componente a modificar");
        scanf("%d",&id);
        i=eProg_buscarPorId(listado,limite,id);
        if(i==-2||i==-3)
        {
            printf("\nEl numero ingresado no pertenece a un Id en funcionamiento");
        }
        else
        {   j=eCat_buscarPorId(categoria,3,listado[i].idCategoria);
            while(opcion!=1&&opcion!=2&&opcion!=3)
            {
            system("cls");
            printf("\nEl usuario a modificar es: %s %s, %s\n 1- Modificar nombre\n 2- Modificar apellido\n",listado[i].nombre, listado[i].apellido, categoria[j].descripcion);
            scanf("%d",&opcion);
            if(opcion==1)
            {
                printf("\nIngrese el nuevo nombre.\n");
                fflush(stdin);
                gets(listado[i].nombre);
            }
            else if(opcion==2)
            {
                printf("\nIngrese su nueva contraseña.\n");
                fflush(stdin);
                gets(listado[i].apellido);
            }else if(opcion==3)
                {

                printf("\nIngrese la nueva categoria del programador\n1-Junior\n2-Semisenior\n3-Senior");
                scanf("%d",&listado[i].idCategoria);
                }

            }
        }
    }
}
