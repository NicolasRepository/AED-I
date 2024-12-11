#include <stdio.h>
#include <time.h>

void merge(int vetor[], int esq, int meio, int dir){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int *v1 = malloc(n1 * sizeof(int));
    int *v2 = malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++){
        v1[i] = vetor[esq + i];
    }
    for(int j = 0; j < n2; j++){
        v2[j] = vetor[meio + 1 + j];
    }

    int i = 0, j = 0, k = esq;
    while(i < n1 && j < n2){
        if (v1[i] <= v2[j]) {
            vetor[k] = v1[i];
            i++;
        } else {
            vetor[k] = v2[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        vetor[k] = v1[i];
        i++;
        k++;
    }
    while(j < n2){
        vetor[k] = v2[j];
        j++;
        k++;
    }
    free(v1);
    free(v2);
}

void mergeSort(int vetor[], int esq, int dir){
    if(esq < dir){
        int meio = (esq+dir)/2;
        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio+1, dir);
        merge(vetor, esq, meio, dir);
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
    mergeSort(vetor, 0, n-1);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("tempo: %f segundos", tempo);
}
