#include <stdio.h>
#include <time.h>

void trocar(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int particionar(int vetor[], int esq, int dir){
    int pivo = vetor[dir];
    int i = esq - 1;

    for(int j = esq; j < dir; j++){
        if (vetor[j] <= pivo){
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

void printVetor(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int n = 20000;
    clock_t inicio, fim;
    double tempo;
    int vetor[n];
    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000000;
    }
    inicio = clock();
    quickSort(vetor, 0, n-1);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("tempo: %f segundos", tempo);
}
