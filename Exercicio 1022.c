#include <stdio.h>

int mdc(int x, int y){
    if(x == y){
        return x;
    }
    else if(y > x){
        int aux = x;
        x = y;
        y = aux;
    }
    for(int i = x/2; i > 0; i--){
        if(x % i == 0 && y % i == 0){
            return i;
        }
    }
    return 1;
}

int main(){
    int n, n1, n2, d1, d2, totalN, totalD, divisor;
    char lixo, operacao;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &n1);
        scanf(" %c", &lixo);
        scanf("%d", &d1);
        scanf(" %c", &operacao);
        scanf("%d", &n2);
        scanf(" %c", &lixo);
        scanf("%d", &d2);
        if(operacao == '+'){
            totalN = (n1*d2 + n2*d1);
            totalD = (d1*d2);
        }
        else if(operacao == '-'){
            totalN = (n1*d2 - n2*d1);
            totalD = (d1*d2);
        }
        else if(operacao == '*'){
            totalN = (n1*n2);
            totalD = (d1*d2);
        }
        else{
            totalN = (n1*d2);
            totalD = (d1*n2);
        }
        divisor = mdc(totalN, totalD);
        printf("%d/%d = %d/%d\n", totalN, totalD, totalN/divisor, totalD/divisor);
    }
    return 0;
}
