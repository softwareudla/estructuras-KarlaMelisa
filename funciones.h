struct Libro{
    int ID;
    char titulo[100];
    char autor[50];
    int anio;
    char estado[10];
};

int menu();
void registrarLibros(struct Libro libros[], int i);
void mostrarLibros(struct Libro libros[], int n);
void buscarLibroId(struct Libro libros[], int id, int n);
void buscarLibroTitulo(struct Libro libros[], char titulo[], int n);
void modificarEstado(struct Libro libros[], int id1, int n);
void eliminarLibro(struct Libro libros[], int id, int n);
