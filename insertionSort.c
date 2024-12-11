#include <stdio.h>

void insertionSort(int vetor[10], int n){
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

void printVetor(int vetor[10], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    int vetor[10] = {4, 5, 6, 2, 4, 7, 8, 33, 1, 9};
    printVetor(vetor, 10);
    insertionSort(vetor, 10);
    printVetor(vetor, 10);
}
