#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu(){
    int opc;
    do{
        printf("---------------------MENU DE SELECCION---------------------\n");
        printf("1. Registrar libro\n2. Mostrar libros\n3. Buscar libro por ID\n4. Buscar libro por titulo\n5. Cambiar estado\n6. Eliminar un libro\n7. Salir\n>>");
        scanf("%d",&opc);
        if (opc<1 && opc>7){
            printf("Ingrese un numero valido \n>>");
            scanf("%d",&opc);
        }
    } while (opc==0);
    return opc;
}

void registrarLibros(struct Libro libros[], int i){
    int len;
    printf("----------------INGRESO DEL LIBRO ID: %d----------------\n",i+1);
    libros[i].ID= i+1;
    printf("TITULO: \n>>");
    fflush(stdin);
    fgets(libros[i].titulo,100, stdin);
    len= strlen(libros[i].titulo)-1;
    libros[i].titulo[len]='\0';
    printf("\nAUTOR: \n>>");
    fflush(stdin);
    fgets(libros[i].autor,50, stdin);
    len= strlen(libros[i].autor)-1;
    libros[i].autor[len]='\0';
    do{
        printf("\nANIO DE PUBLICACION: \n>>");
        scanf("%d",&libros[i].anio);
        if (libros[i].anio<0 || libros[i].anio>2024){
            printf("Ingrese un anio valido \n>>");
            scanf("%d",&libros[i].anio);
        }
    } while (libros[i].anio>2024 || libros[i].anio<0);
    strcpy(libros[i].estado,"Disponible"); 
}

void mostrarLibros(struct Libro libros[], int n) {
    printf("%-5s %-30s %-20s %-6s %-10s\n", "ID", "TITULO", "AUTOR", "ANIO", "ESTADO");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (libros[i].ID != 0) { // Mostrar solo libros con ID válido
            printf("%-5d %-30s %-20s %-6d %-10s\n",
                   libros[i].ID,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio,
                   libros[i].estado);
        }
    }
}


void buscarLibroId(struct Libro libros[], int id, int n){
    int validar=0;
    for (int i = 0; i < n ; i++){
        if (libros[i].ID == id){
            printf("La informacion del libro buscado es: \nID: %d\t\tTitulo: %s\t\tAutor: %s\t\tAnio: %d\t\tEstado: %s\n",libros[i].ID,
                                                                                                                        libros[i].titulo,
                                                                                                                        libros[i].autor,
                                                                                                                        libros[i].anio,
                                                                                                                        libros[i].estado);
            validar =1;
        }
    }
    if(validar==0){
        printf("No se encontro un libro con el ID: %d\n",id);
    }
}

void buscarLibroTitulo(struct Libro libros[], char titulo[], int n){
    int len;
    len= strlen(titulo)-1;
    titulo[len]='\0';
    int validar=0;
    for (int i = 0; i < n; i++){
        if (strcmp(libros[i].titulo, titulo) == 0) {
             printf("La informacion del libro buscado es: \nID: %d\t\tTitulo: %s\t\tAutor: %s\t\tAnio: %d\t\tEstado: %s\n",libros[i].ID,
                                                                                                                        libros[i].titulo,
                                                                                                                        libros[i].autor,
                                                                                                                        libros[i].anio,
                                                                                                                        libros[i].estado);
            validar =1;
        }
    }
    if(validar==0){
        printf("No se encontro un libro con el titulo: %s\n",titulo);
    }
}

void modificarEstado(struct Libro libros[], int id, int n){
    int validar= 0, opc;
    for (int i = 0; i < n; i++){
        if (libros[i].ID == id){
            do{
                printf("El estado actual del libro %d es: %s\nDesea modificar a\n1. Disponible\n2. Prestado\n>>",id,libros[i].estado);
                scanf("%d",&opc);
                if (opc<0 && opc>2){
                    printf("Ingrese un numero valido \n>>");
                    scanf("%d",&opc);
                }
            } while (opc==0);
            switch (opc){
            case 1:
                strcpy(libros[i].estado,"Disponible");
                break;
            case 2:
                strcpy(libros[i].estado,"Prestado");
                break;
            default: 
                break;
            }
            validar= 1;
            printf("El nuevo estado del libro %d es %s\n",id, libros[i].estado);
        }
    }
    if (validar == 0){
        printf("No se encontro un libro con el ID: %d\n",id);
    }
    
}

void eliminarLibro(struct Libro libros[], int id, int n){
    int validar= 0;
    int opc= 0;
    do{
        for (int i = 0 ; i < n; i++){
            if (libros[i].ID == id){
                validar = 1;
                printf("Libro %s con ID %d encontrado\n",libros[i].titulo, libros[i].ID);
                printf("Esta seguro que desea eliminar este libro?\n1.Si\n2.No\n>> ");
                int confirmacion;
                scanf("%d", &confirmacion);
                if (confirmacion == 1){
                    // Desplazar elementos hacia arriba
                    for (int j = i; j < n; j++){
                        strcpy(libros[j].titulo, libros[j + 1].titulo);
                        strcpy(libros[j].autor, libros[j + 1].autor);
                        strcpy(libros[j].estado, libros[j + 1].estado);
                        libros[j].ID = libros[j+1].ID;
                        libros[j].anio = libros[j + 1].anio;
                    }
                    // Limpiar el último elemento
                    strcpy(libros[n-1].titulo, "");
                    strcpy(libros[n-1].autor, "");
                    strcpy(libros[n-1].estado, "");
                    libros[n-1].ID = '\0';
                    libros[n-1].anio = '\0';
                    printf("Libro eliminado exitosamente.\n");
                } else { printf("Operacion cancelada.\n");
                }
                break;
            }
        }
    if (!validar) {
        printf("Libro no encontrado.\n");
    }
    } while (opc==1);  
    printf("--------------------------LISTA DE LIBROS ACTUALIZADA--------------------------\n");
    printf("%-5s %-30s %-20s %-6s %-10s\n", "ID", "Titulo", "Autor", "Anio", "Estado");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        if (libros[i].ID != 0) { // Mostrar solo libros con ID válido
            printf("%-5d %-30s %-20s %-6d %-10s\n",
                   libros[i].ID,
                   libros[i].titulo,
                   libros[i].autor,
                   libros[i].anio,
                   libros[i].estado);
        }
    }
}
