#include <stdio.h>
 
int main(){
    int lixo, qt, i = 2;
    float valor, total = 0;
    while(i--){
        scanf("%d %d %f", &lixo, &qt, &valor);
        total += (valor*qt);
    }
    printf("VALOR A PAGAR: R$ %.2f\n", total);
    return 0;
}
