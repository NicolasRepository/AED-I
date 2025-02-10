#include <stdio.h>
#include <string.h>

int main(){
    int n, maior, tam, pri = 0;
    char palavras[50][50];
    scanf("%d", &n);
    while(n){
        if(pri){
            printf("\n");
        }
        else{
            pri++;
        }
        getchar();
        maior = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", &palavras[i]);
            if(strlen(palavras[i]) > maior){
                maior = strlen(palavras[i]);
            }
        }
        for(int i = 0; i < n; i++){
            tam = 0;
            for(int j = 0; j < maior - strlen(palavras[i]); j++){
                printf(" ");
            }
            printf("%s\n", palavras[i]);
        }
        scanf("%d", &n);
    }
    return 0;
}
