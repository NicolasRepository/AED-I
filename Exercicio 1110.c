#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, pilha[101] = {}, descarte[50] = {}, k;
    scanf("%d", &n);
    while(n){
        k = 0;
        for(int i = 0; i < n; i++){
            pilha[i] = i+1;
        }
        for(int i = 0; i < n; i++){
            descarte[i] = pilha[i*2];
            pilha[n+k] = pilha[i*2+1];
            k++;
        }
        printf("Discarded cards: 1");
        for(int i = 1; i < n-1; i++){
            printf(", %d", descarte[i]);
        }
        printf("\nRemaining card: %d\n", pilha[n+k-2]);
        scanf("%d", &n);
    }
    return 0;
}
