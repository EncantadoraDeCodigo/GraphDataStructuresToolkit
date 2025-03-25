#include <stdio.h>
#include <stdlib.h>
#define MAX_NODOS 100

// Matriz de Adyacencia
typedef struct
{
    int matriz[MAX_NODOS][MAX_NODOS];
    int numNodos;
} GrafoMatriz;

void inicializarMatriz(GrafoMatriz *g, int nodos)
{
    g->numNodos = nodos;
    for (int i = 0; i < nodos; i++)
    {
        for (int j = 0; j < nodos; j++)
        {
            g->matriz[i][j] = 0; // 0 = sin arista
        }
    }
}

void agregarAristaMatriz(GrafoMatriz *g, int origen, int destino, int peso)
{
    g->matriz[origen][destino] = peso;
    g->matriz[destino][origen] = peso;
}

void ImprimirMatrizCompleta(GrafoMatriz *g)
{
    for (int i = 0; i < g->numNodos; i++)
    {
        for (int j = i; j < g->numNodos; j++)
        {
            if (i != j)
            {
                int n = g->matriz[i][j];
                if (n != 0)
                {
                    printf("The weight between the nodes %d and %d, is %d.\n", i, j, n);
                }
            }
        }
    }
}

int main()
{
    // Definimos la Matriz donde nodo es el número de nodos que se generarán dentro de aquella matriz.
    int nodos = 6;
    GrafoMatriz* matriz = (GrafoMatriz *)malloc(sizeof(GrafoMatriz));
    inicializarMatriz(matriz, nodos);
    // Agregamos las aristas, donde conectaremos bidireccionalmente el origen y el destino con el mismo peso.
    agregarAristaMatriz(matriz, 2, 4, 6);
    agregarAristaMatriz(matriz, 0, 1, 4);
    agregarAristaMatriz(matriz, 0, 2, 4);
    agregarAristaMatriz(matriz, 2, 3, 5);
    agregarAristaMatriz(matriz, 1, 3, 5);
    // Llamamos la función para imprimir el grafo completo.
    ImprimirMatrizCompleta(matriz);
    return (0);
}