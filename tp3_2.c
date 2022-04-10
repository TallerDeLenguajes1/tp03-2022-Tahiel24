#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *Buff, *nombres[5];

    Buff = (char *)malloc(100 * sizeof(char));

    puts("Ingrese sus cadenas de texto: ");
    for (int i = 0; i < 5; i++)
    {
        gets(Buff);
        nombres[i] = (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
    }

    puts("Las cadenas ingresadas son: ");
    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }

    //free(nombres[i]);
    free(Buff);
    return 0;
}
