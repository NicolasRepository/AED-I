#include <stdio.h>

void ordenar(int vagoes[], int tam, int* swap){
    for(int i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - i - 1; j++){
            if(vagoes[j] > vagoes[j + 1]){
                int temp = vagoes[j];
                vagoes[j] = vagoes[j + 1];
                vagoes[j + 1] = temp;
                (*swap)++;
            }
        }
    }
}

int main(){
    int n, l, vagoes[50], swap;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &l);
        swap = 0;
        for(int i = 0; i < l; i++){
            scanf("%d", &vagoes[i]);
        }
        ordenar(vagoes, l, &swap);
        printf("Optimal train swapping takes %d swaps.\n", swap);
    }
    return 0;
}
