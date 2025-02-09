#include <stdio.h>
#include <string.h>

int main(){
    int n, tam, abriu, total;
    char linha[1001];
    scanf("%d", &n);
    getchar();
    while(n--){
        scanf("%s", &linha);
        tam = strlen(linha);
        abriu = 0;
        total = 0;
        for(int i = 0; i < tam; i++){
            if(linha[i] == '<'){
                abriu++;
            }
            else if(linha[i] == '>' && abriu > 0){
                abriu--;
                total++;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}
