#include <stdio.h>
#include <string.h>

int main(){
    int n, letras[26], maior;
    char linha[201];
    scanf("%d", &n);
    getchar();
    while(n--){
        maior = 0;
        for(int i = 0; i < 26; i++){
            letras[i] = 0;
        }
        fgets(linha, sizeof(linha), stdin);
        for(int i = 0; linha[i] != '\n'; i++){
            if(linha[i] > 64){
                if(linha[i] < 97){
                    linha[i] += 32;
                }
                letras[linha[i] - 97]++;
                if(letras[linha[i] - 97] > maior){
                    maior = letras[linha[i] - 97];
                }
            }
        }
        for(int i = 0; i < 26; i++){
            if(letras[i] == maior){
                printf("%c", i + 97);
            }
        }
        printf("\n", maior);
    }
    return 0;
}
