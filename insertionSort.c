#include <stdio.h>
#include <time.h>

void insertionSort(int vetor[], int n){
    int pivo, j;
    for(int i = 1; i < n; i++){
        pivo = vetor[i];
        j = i-1;
        while(j >= 0 && vetor[j] > pivo){
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = pivo;
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
    printVetor(vetor, n);
    inicio = clock();
    insertionSort(vetor, n);
    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printVetor(vetor, n);
    printf("tempo: %f segundos", tempo);
}
