#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    //Declaracion de variables
    int cant;
    char *Buff;

    //Creacion de la lista de usuarios
    puts("Ingrese la cantidad de nombres a registrar: ");
    scanf("%d", &cant);
    char *nombres[cant];
    
    //Asignado de memoria dinamica
    Buff = (char *)malloc(100 * sizeof(char));
    

    
    puts("Ingrese sus cadenas de texto: ");
    for (int i = 0; i < cant; i++)
    {
        fflush(stdin);
        gets(Buff);
        nombres[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
    }

    puts("Las cadenas ingresadas son: ");
    for (int i = 0; i < cant; i++)
    {
        puts(nombres[i]);
    }

    //free(nombres[i]);
    free(Buff);
    return 0;
}
