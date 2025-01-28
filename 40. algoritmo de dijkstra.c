#include <stdio.h>
#include <limits.h>
#define V 5

//função "distância mínima": encontra o vértice de menor distância que ainda não foi processado
int distmin(int dist[], int controle[]) {
    int min = INT_MAX;
    int indice_min;

    for (int v = 0; v < V; v++)
        if (controle[v] == 0 && dist[v] <= min) {
            min = dist[v];
            indice_min = v;
        }

    return indice_min;
}

//função dijkstra: implementa o algoritmo
void dijkstra(int grafo[V][V], int origem) {
    int dist[V]; //armazenar a menor distância do vértice de origem para cada vértice
    int controle[V]; //acompanha os vértices já processados

    //inicializa as distâncias como "infinito" e "controle[]" como falso (0, porque nenhum vértice foi processado no momento)
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        controle[i] = 0;
    }

    //define a distância do vértice de origem para ele mesmo como 0
    dist[origem] = 0;

    //encontra o caminho mais curto para todos os vértices
    for (int count = 0; count < V - 1; count++) {
        //escolhe o vértice com a menor distância
        int u = distmin(dist, controle);

        //marca o vértice como processado
        controle[u] = 1;

        //atualiza as distâncias dos vértices adjacentes
        for (int v = 0; v < V; v++)
            if (!controle[v] && grafo[u][v] && dist[u] != INT_MAX
                && dist[u] + grafo[u][v] < dist[v])
                dist[v] = dist[u] + grafo[u][v];
    }

    //exibe os resultados
    printf("vértice \t distância da origem\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main() {
    //grafo representado como uma matriz de adjacências
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 1},
        {1, 2, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    //chama o algoritmo para o vértice de origem 0
    dijkstra(graph, 0);

    return 0;
}


/* explicando o código 
controle[], matriz que acompanha os vértices que foram processados. basicamente, indica se um vértice já foi incluído na árvore de caminhos mínimos (se a menor distância conhecida desse vértice a partir da origem foi encontrada)
*/
