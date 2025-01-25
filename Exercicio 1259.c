#include <stdio.h>
#include <stdlib.h>

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

void printVetorP(int vetor[], int n){
    for(int i = 0; i < n; i++){
        printf("%d\n", vetor[i]);
    }
}

void printVetorI(int vetor[], int n){
    for(int i = n-1; i >= 0; i--){
        printf("%d\n", vetor[i]);
    }
}

int main() {
    int n, k, p = 0, m = 0;
    scanf("%d", &n);
    int pares[n], impares[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        if(k%2 == 0){
            pares[p] = k;
            p++;
        }
        else{
            impares[m] = k;
            m++;
        }
    }
    quickSort(pares, 0, p-1);
    quickSort(impares, 0, m-1);
    printVetorP(pares, p);
    printVetorI(impares, m);
    return 0;
}
