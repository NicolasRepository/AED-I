#include <stdio.h>

void trocar(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particionar(int vetor[], int esq, int dir){
    int pivo = vetor[dir];
    int i = esq - 1;

    for(int j = esq; j < dir; j++){
        if (vetor[j] >= pivo){
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[dir]);
    return i + 1;
}

void quickSort(int vetor[], int esq, int dir){
    if (esq < dir){
        int pivo = particionar(vetor, esq, dir);
        quickSort(vetor, esq, pivo-1);
        quickSort(vetor, pivo+1, dir);
    }
}

int main() {
    int n, m, p[1000], pO[1000], total;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &m);
        total = 0;
        for(int j = 0; j < m; j++){
            scanf("%d", &p[j]);
            pO[j] = p[j];
        }
        quickSort(pO, 0, m-1);
        for(int j = 0; j < m; j++){
            if(pO[j] == p[j]){
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
