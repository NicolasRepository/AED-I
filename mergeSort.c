#include <stdio.h>

void merge(int vetor[], int esq, int meio, int dir){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int v1[n1], v2[n2];

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
    int n;
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        vetor[i] = rand() % 1000;
    }
    printVetor(vetor, 10);
    mergeSort(vetor, 0, n-1);
    printVetor(vetor, 10);
}
