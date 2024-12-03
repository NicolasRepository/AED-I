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


#include <stdio.h>

void mergeSort(int vetor[10], int esq, int meio, int dir){
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int v1[n1], v2[n2];
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

    for(int i = 0; i < n1; i++){
        v1[i] = vetor[esq + i];
    }
    for(int j = 0; j < n2; j++){
        v2[j] = vetor[meio + 1 + j];
    }
    
    int i = 0, j = 0, k = es1;
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
    mergeSort(vetor, 10);
    printVetor(vetor, 10);
}
