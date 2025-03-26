#include <stdio.h>
#include <stdlib.h>
#define MAX_NODOS 100
// Definición de un nodo de la lista de adyacencia.
typedef struct Nodo
{
    int destino;
    int peso;
    struct Nodo *siguiente; // Siguiente es un puntero a struct Nodo.
} Nodo;

typedef struct GrafoLista
{
    Nodo *lista[MAX_NODOS];
    int numNodos;
} GrafoLista;

void inicializarLista(GrafoLista* g, int nodos)
{
    g->numNodos = nodos;
    for (int i = 0; i < nodos; i++)
    {
        g->lista[i] = NULL;
    }
}

void agregarAristaLista(GrafoLista* g, int origen, int destino, int peso)
{
    // Conexión en una dirección.
    Nodo* nuevo1 = (Nodo*)malloc(sizeof(Nodo)); // Use listas enlazada dinámicas, por lo requiere reserva de memoria en el heap para agregar la conexión entre nodos.
    nuevo1->destino = destino;
    nuevo1->peso = peso;
    nuevo1->siguiente = g->lista[origen];
    g->lista[origen] = nuevo1;

    // Conexión en dirección contraria para que sea bidireccional.
    Nodo* nuevo2 = (Nodo*)malloc(sizeof(Nodo));
    nuevo2->destino = origen;
    nuevo2->peso = peso;
    nuevo2->siguiente = g->lista[destino];
    g->lista[destino] = nuevo2;
}

void imprimirListaCompleta(GrafoLista *g)
{
    for (int i = 0; i < g->numNodos; i++)
    { // Recorre nodo tras nodo.
        if (g->lista[i] != NULL)
        {
            Nodo *temp = g->lista[i];
            for (Nodo *j = temp; j != NULL; j = j->siguiente)
            { // Explora cada conexión.
                if (i < j->destino)
                {
                    printf("The weight between the noodes %d and %d, is %d\n", i, j->destino, j->peso);
                }
            }
        }
    }
}

int main()
{
    int nodos = 3;
    GrafoLista *lista = (GrafoLista *)malloc(sizeof(GrafoLista));
    inicializarLista(lista, MAX_NODOS); // Asegurar que el grafo empiece en un estado limpio y válido.
    // Se establecen los valores para vértices, aristas y peso.
    agregarAristaLista(lista, 1, 5, 4);
    agregarAristaLista(lista, 2, 0, 3);
    agregarAristaLista(lista, 1, 5, 2);

    imprimirListaCompleta(lista);
    return (0);
}