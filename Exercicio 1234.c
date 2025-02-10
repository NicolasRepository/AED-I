#include <stdio.h>
#include <string.h>

int main(){
    int status;
    char linha[51];
    while(fgets(linha, sizeof(linha), stdin)){
        linha[strcspn(linha, "\n")] = '\0';
        status = 0;
        for(int i = 0; i < 50 && linha[i] != '\n'; i++){
            if(linha[i] > 64){
                if(status % 2 == 0 && linha[i] > 96 && linha[i] < 124){
                    linha[i] -= 32;
                }
                else if(status % 2 == 1 && linha[i] > 64 && linha[i] < 97){
                    linha[i] += 32;
                }
                status++;
            }
        }
        printf("%s\n", linha);
    }
    return 0;
}
