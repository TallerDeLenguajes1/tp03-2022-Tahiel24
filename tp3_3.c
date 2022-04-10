#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

// Estructuras


struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};
typedef struct Producto * produc;

struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    struct Producto *Productos          // El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};
typedef struct Cliente * Lista;

//Funciones
float calcularPrecio(float precioUn, int cant);

//Funcion principal
int main()
{
    srand (time(NULL));
    char *TiposProductos[]={"Galletas","Snack","Cigarillos","Caramelos","Bebidas"};
    char *aux;
    int cantClientes,numAux;
    float precioProductos=0;
    produc proct;

    //Cantidad de clientes
    puts("Ingrese la cantidad de clientes a registrar: ");
    scanf("%d", &cantClientes);

    //Generar dinamicamente la cantidad de clientes 
    Lista listas;
    listas=(Lista*)malloc(cantClientes*sizeof(Lista*));
    aux = (char *) malloc(100*sizeof(char));


      for (int i = 0; i < cantClientes; i++)
    {
        fflush(stdin);
        //ID del cliente
        (listas+i)->ClienteID=i+1;

        //Nombre del cliente
        puts("Ingrese nombre del cliente: ");
        gets(aux);
        (listas+i)->NombreCliente=(char*)malloc((strlen(aux)+1)*sizeof(char));
        strcpy((listas+i)->NombreCliente,aux);

        //Cantidad aleatoria de productos a pedir a pedir

        (listas+i)->CantidadProductosAPedir=rand()%5+1;
        
        //Reserva dinamica de memoria para los productos
        (listas+i)->Productos=(produc*)malloc(((listas+i)->CantidadProductosAPedir)*sizeof(produc));

        //Llenado de productos para cada cliente
        for (int j = 0; j < (listas+i)->CantidadProductosAPedir; j++)
        {
            //ID
            (((listas+i)->Productos)+j)->ProductoID=j+1;
            //Cantidad aleatoria de unidades del producto
            (((listas+i)->Productos)+j)->Cantidad=rand()%10+1;
            //Producto aleatorio
            numAux=rand()%5;
            (((listas+i)->Productos)+j)->TipoProducto=(char*)malloc((strlen(TiposProductos[numAux])));
            strcpy((((listas+i)->Productos)+j)->TipoProducto,TiposProductos[numAux]);
            //Precio del producto
            (((listas+i)->Productos)+j)->PrecioUnitario=rand()%91+10;
        }
    
    }
    //Mostrar datos

    puts("-----------Mostrar clientes: -----------------");
    for (int i = 0; i <cantClientes ; i++)
    {
        printf("\nID:%d\n", i+1);
        puts("Nombre del cliente: ");
        puts((listas+i)->NombreCliente);
        printf("Cantidad de productos a pedir: %d\n",(listas+i)->CantidadProductosAPedir);
        puts("----------Descripcion de los productos: ------------------");
        for (int j = 0; j < (listas+i)->CantidadProductosAPedir; j++)
        {
            printf("ID del producto:%d \n",j+1);
            printf("Cantidad de unidades: %d\n",((((listas+i)->Productos)+j)->Cantidad));
            puts("Tipo de producto: ");
            puts((((listas+i)->Productos)+j)->TipoProducto);
            printf("Precio unitario del producto: %.2f\n",(((listas+i)->Productos)+j)->PrecioUnitario);
            puts("-----------------------------------");
            precioProductos +=calcularPrecio((((listas+i)->Productos)+j)->PrecioUnitario,(((listas+i)->Productos)+j)->Cantidad);
        }
    printf("Costo total de los productos: %.2f\n\n\n", precioProductos);
   
    }
    //Liberar la memoria

    for (int i = 0; i < cantClientes; i++)
    {
        free((listas+ i)->Productos);
        for (int j = 0; j <(listas+i)->CantidadProductosAPedir ; j++)
        {
            free((((listas + i)->Productos) + j)->TipoProducto);
        }
        
    }
    free(listas);
    free(aux);

    return 0;
}

//Desarrollo de funciones
float calcularPrecio(float precioUn, int cant){
    return precioUn*cant;
}