#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m, lixo, arestas, arestasT, x, y;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &lixo);
        scanf("%d %d", &m, &arestas);
        arestasT = arestas;
        int *grafo = (int *)calloc(m * m, sizeof(int));
        for(int j = 0; j < arestas; j++){
            scanf("%d %d", &x, &y);
            if(grafo[x * m + y] % 2 == 1){
                arestasT--;
            }
            grafo[x * m + y]++;
            grafo[y * m + x]++;
        }
        free(grafo);
        printf("%d\n", arestasT*2);
    }
    return 0;
}
