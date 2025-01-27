#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void trocar(char *a, char *b){
    char aux = *a;
    *a = *b;
    *b = aux;
}

int particionar(char string[], int esq, int dir){
    char pivo = string[dir];
    int i = esq - 1;

    for(int j = esq; j < dir; j++){
        if (string[j] <= pivo){
            i++;
            trocar(&string[i], &string[j]);
        }
    }

    trocar(&string[i + 1], &string[dir]);
    return i + 1;
}

void quickSort(char string[], int esq, int dir){
    if (esq < dir){
        int pivo = particionar(string, esq, dir);
        quickSort(string, esq, pivo - 1);
        quickSort(string, pivo + 1, dir);
    }
}

int permutacao(char *string, int qt){
    int i = qt - 2;
    while (i >= 0 && string[i] >= string[i + 1]) i--;
    if (i < 0) return 0;
    int j = qt - 1;
    while (string[j] <= string[i]) j--;
    trocar(&string[i], &string[j]);
    for (int l = i + 1, r = qt - 1; l < r; l++, r--){
        trocar(&string[l], &string[r]);
    }
    return 1;
}

int main(){
    int n;
    char string[11];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", string);
        int qt = strlen(string);
        quickSort(string, 0, qt - 1);
        do{
            printf("%s\n", string);
        }
        while(permutacao(string, qt));
        printf("\n");
    }

    return 0;
}
