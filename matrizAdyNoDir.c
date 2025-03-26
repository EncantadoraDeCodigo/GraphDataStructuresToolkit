#include <stdio.h>
#include <stdlib.h>
#define MAX_NODOS 100 // directiva de procesador

// Matriz de adyacencia
typedef struct
{
    int matriz[MAX_NODOS][MAX_NODOS];
    int numNodos;
} Grafomatriz;

void inicializarMatriz(Grafomatriz *g, int nodos)
{
    g->numNodos = nodos;
    for (int i = 0; i < nodos; i++)
    {
        for (int j = 0; j < nodos; j++)
        {
            g->matriz[i][j] = 0; // 0 = sin aristas
        }
    }
}

void agregarAristaMatriz(Grafomatriz *g, int origen, int destino, int peso)
{
    g->matriz[origen][destino] = peso;
    g->matriz[destino][origen] = peso;
}

void imprimirMatrizCompleta(Grafomatriz *g)
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
                    printf("The weigth between the nodes %d and %d, is %d\n", i, j, n);
                }
            }
        }
    }
}

int main()
{
    // Se define la matriz donde nodo es el número de nodos que se generarán dentro de aquella matriz.
    int nodos = 6;
    Grafomatriz* matriz = (Grafomatriz *)malloc(sizeof(Grafomatriz)); // Su memoria se reserva automaticamente en el stack, por tener un tamaño fijo.
    inicializarMatriz(matriz, nodos);
    // Se agregan las aristas, donde se conectan bidireccional mente el origen y destino junto a su peso
    agregarAristaMatriz(matriz, 0, 1, 3); // Conexión entre 0 y 1
    agregarAristaMatriz(matriz, 0, 2, 4); // Conexión entre 0 y 2
    agregarAristaMatriz(matriz, 1, 3, 5); // Conexión entre 1 y 3
    agregarAristaMatriz(matriz, 2, 4, 6); // Conexión entre 2 y 4
    agregarAristaMatriz(matriz, 3, 5, 2); // Conexión entre 3 y 5

    // Se llama la función para imprimir el grafo completo.
    imprimirMatrizCompleta(matriz);
    return 0;
}
