#include <stdio.h>
#include "funciones.h"
#include <string.h>

int main (int argc, char *argv[]) {

    struct Libro libros[20];
    int opc, op;
    int i=0;
    do{
        opc = menu();
        switch (opc)
        {
            case 1:
                if (i < 20) { // Limitar a un máximo de 20 registros
                    registrarLibros(libros, i);
                    i++;
                } else {
                printf("No se pueden registrar mas de 20 libros.\n");
                }
                break;
            case 2:
                mostrarLibros(libros, i);
                break;
            case 3:
                if (i > 0) {
                    int id;
                    printf("----------------BUSQUEDA POR ID----------------\nIngrese el ID del libro a buscar: \n>>");
                    scanf("%d", &id);
                    buscarLibroId(libros, id, i);
                }else {
                    printf("No hay libros registrados.\n");
                }
                break;
            case 4:
                if (i > 0){
                    char titulo[100];
                    printf("----------------BUSQUEDA POR TITULO----------------\nIngrese el titulo del libro a buscar: \n>>");
                    fflush(stdin);
                    fgets(titulo,100, stdin);
                    buscarLibroTitulo(libros, titulo, i);
                } else {
                    printf("No hay libros registrados.\n");
                }
                break;
            case 5:
                if (i > 0){
                    int id1;
                    printf("----------------MODIFICACION ESTADO----------------\nIngrese el ID del libro a modificar: ");
                    scanf("%d", &id1);
                    modificarEstado(libros, id1, i);
                }else {
                    printf("No hay libros registrados.\n");
                }
                break;
            case 6:
                if (i > 0){
                    int id2;
                    printf("----------------ELIMINACION----------------\nIngrese el ID del libro a eliminar: ");
                    scanf("%d", &id2);
                    eliminarLibro(libros, id2, i);
                }else {
                    printf("No hay libros registrados.\n");
                }
                break;
            case 7:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Ingrese una opcion válida.\n");
        }
        
    }while( opc != 7);
    
    return 0;
}
