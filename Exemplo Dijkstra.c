#include <stdio.h>
#include <limits.h>
#define INF INT_MAX

int minDistancia(int dist[], int visitado[], int n){
    int min = INT_MAX, indiceMin;
    for(int v = 0; v < n; v++){
        if(visitado[v] == 0 && dist[v] <= min){
            min = dist[v];
            indiceMin = v;
        }
    }
    return indiceMin;
}

void dijkstra(int grafo[250][250], int origem, int n){
    int dist[n];
    int visitado[n];
    for(int i = 0; i < n; i++){
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;
    for(int count = 0; count < n - 1; count++){
        int u = minDistancia(dist, visitado, n);
        if(u == -1) break;
        visitado[u] = 1;
        for(int v = 0; v < n; v++){
            if(!visitado[v] && grafo[u][v] != INF && dist[u] != INF && dist[u] + grafo[u][v] < dist[v]){
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

int main(){
    int n, m, c, k, grafo[250][250], u, v, p;
    while(scanf("%d %d %d %d", &n, &m, &c, &k) == 4 && n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j){
                    grafo[i][j] = 0;
                }
                else{
                    grafo[i][j] = INF;
                }
            }
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &p);
            grafo[u][v] = grafo[v][u] = p;
        }
        dijkstra(grafo, k, n);
    }
    return 0;
}
