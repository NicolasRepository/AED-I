#include <stdio.h>

int main() {
    int n, tempo, errado[26], total, sucesso;
    char letra, status[10];
    scanf("%d", &n);
    while(n){
        total = 0;
        sucesso = 0;
        for(int i = 0; i < 26; i++){
            errado[i] = 0;
        }
        for(int j = 0; j < n; j++){
            getchar();
            scanf("%c", &letra);
            scanf("%d", &tempo);
            getchar();
            scanf("%s", status);
            if(status[0] == 'c'){
                total += tempo + errado[letra - 65]*20;
                sucesso++;
            }
            else{
                errado[letra-65]++;
            }
        }
        printf("%d %d\n", sucesso, total);
        scanf("%d", &n);
    }
    return 0;
}
